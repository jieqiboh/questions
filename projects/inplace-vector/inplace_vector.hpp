#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>      // std::move, std::forward
#include <new>          // placement new, std::launder
#include <iterator>
#include <initializer_list>

// ---------------------------------------------------------------------------
// inplace_vector<T, N>
//
// Fixed-capacity vector backed by aligned stack storage.
// No heap allocation ever. Suitable for HFT / real-time paths.
//
// Key concepts demonstrated:
//   1. alignas / std::aligned_storage  -- correct alignment for T
//   2. placement new                   -- constructing T in raw bytes
//   3. Manual destructor calls         -- ~T() without deallocation
//   4. std::launder                    -- defeating compiler pointer provenance
//   5. Object lifetime rules           -- construct before use, destroy before reuse
//   6. move/copy semantics             -- element-wise, no allocator tricks
// ---------------------------------------------------------------------------

template <typename T, std::size_t N>
class inplace_vector {
public:
    // -----------------------------------------------------------------------
    // Types
    // -----------------------------------------------------------------------
    using value_type      = T;
    using size_type       = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;
    using iterator        = T*;
    using const_iterator  = const T*;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // -----------------------------------------------------------------------
    // Storage
    //
    // alignas(T) ensures the raw bytes satisfy T's alignment requirement.
    // We store N * sizeof(T) bytes: enough for N live objects of type T.
    //
    // Why not just T storage_[N]?
    //   -> That would VALUE-INITIALISE N Ts immediately, calling constructors
    //      for objects we haven't asked to construct yet. inplace_vector must
    //      give precise lifetime control: object only exists after push_back.
    // -----------------------------------------------------------------------
    alignas(T) unsigned char storage_[N * sizeof(T)];
    size_type size_ = 0;

    // -----------------------------------------------------------------------
    // Helpers: typed pointer into raw storage
    //
    // std::launder is necessary when the compiler might cache the address of
    // whatever previously lived at this location.  It tells the compiler:
    // "trust me, a valid T now lives here; don't reuse a stale pointer."
    // -----------------------------------------------------------------------
    pointer data_ptr() noexcept {
        return std::launder(reinterpret_cast<T*>(storage_));
    }
    const_pointer data_ptr() const noexcept {
        return std::launder(reinterpret_cast<const T*>(storage_));
    }

public:
    // -----------------------------------------------------------------------
    // Constructors / destructor
    // -----------------------------------------------------------------------

    inplace_vector() noexcept = default;

    // Fill constructor
    explicit inplace_vector(size_type count, const T& value = T{}) {
        if (count > N) throw std::length_error("inplace_vector: count > N");
        for (size_type i = 0; i < count; ++i)
            construct_at(i, value);
        size_ = count;
    }

    // Range constructor
    template <typename InputIt>
    inplace_vector(InputIt first, InputIt last) {
        for (; first != last; ++first)
            push_back(*first);
    }

    // Initializer-list constructor
    inplace_vector(std::initializer_list<T> il) {
        for (auto& v : il)
            push_back(v);
    }

    // Copy constructor: copy each live element via placement new
    inplace_vector(const inplace_vector& other) {
        for (size_type i = 0; i < other.size_; ++i)
            construct_at(i, other.data_ptr()[i]);
        size_ = other.size_;
    }

    // Move constructor: move-construct each element, then destroy source
    inplace_vector(inplace_vector&& other) noexcept(std::is_nothrow_move_constructible_v<T>) {
        for (size_type i = 0; i < other.size_; ++i)
            construct_at(i, std::move(other.data_ptr()[i]));
        size_ = other.size_;
        other.clear();          // destroy source elements; size_ -> 0
    }

    // Destructor: manually call ~T() for every live object.
    // The storage itself is on the stack, so it reclaims automatically.
    ~inplace_vector() {
        clear();
    }

    // Copy assignment
    inplace_vector& operator=(const inplace_vector& other) {
        if (this == &other) return *this;
        clear();
        for (size_type i = 0; i < other.size_; ++i)
            construct_at(i, other.data_ptr()[i]);
        size_ = other.size_;
        return *this;
    }

    // Move assignment
    inplace_vector& operator=(inplace_vector&& other) noexcept(
        std::is_nothrow_move_constructible_v<T>) {
        if (this == &other) return *this;
        clear();
        for (size_type i = 0; i < other.size_; ++i)
            construct_at(i, std::move(other.data_ptr()[i]));
        size_ = other.size_;
        other.clear();
        return *this;
    }

    // -----------------------------------------------------------------------
    // Capacity
    // -----------------------------------------------------------------------
    [[nodiscard]] size_type size()     const noexcept { return size_; }
    [[nodiscard]] size_type max_size() const noexcept { return N; }
    [[nodiscard]] size_type capacity() const noexcept { return N; }
    [[nodiscard]] bool      empty()    const noexcept { return size_ == 0; }
    [[nodiscard]] bool      full()     const noexcept { return size_ == N; }

    // -----------------------------------------------------------------------
    // Element access
    // -----------------------------------------------------------------------
    reference operator[](size_type i) noexcept {
        return data_ptr()[i];
    }
    const_reference operator[](size_type i) const noexcept {
        return data_ptr()[i];
    }

    reference at(size_type i) {
        if (i >= size_) throw std::out_of_range("inplace_vector::at");
        return data_ptr()[i];
    }
    const_reference at(size_type i) const {
        if (i >= size_) throw std::out_of_range("inplace_vector::at");
        return data_ptr()[i];
    }

    reference       front()       noexcept { return data_ptr()[0]; }
    const_reference front() const noexcept { return data_ptr()[0]; }
    reference       back()        noexcept { return data_ptr()[size_ - 1]; }
    const_reference back()  const noexcept { return data_ptr()[size_ - 1]; }

    pointer       data()       noexcept { return data_ptr(); }
    const_pointer data() const noexcept { return data_ptr(); }

    // -----------------------------------------------------------------------
    // Modifiers
    // -----------------------------------------------------------------------

    // push_back (copy): construct a T in the next slot via placement new.
    // There is NO operator new[] here; we supply the address ourselves.
    void push_back(const T& value) {
        check_capacity();
        construct_at(size_, value);
        ++size_;
    }

    // push_back (move)
    void push_back(T&& value) {
        check_capacity();
        construct_at(size_, std::move(value));
        ++size_;
    }

    // emplace_back: forward args directly to T's constructor in-place.
    // This is the canonical zero-copy insertion: no temporary T ever created.
    template <typename... Args>
    reference emplace_back(Args&&... args) {
        check_capacity();
        ::new (slot(size_)) T(std::forward<Args>(args)...);
        return data_ptr()[size_++];
    }

    // pop_back: MANUALLY call the destructor.  Memory is not freed
    // (there's nothing to free), but the object's lifetime ends here.
    void pop_back() noexcept {
        --size_;
        destroy_at(size_);
    }

    // clear: destroy all live elements in reverse order (convention).
    void clear() noexcept {
        while (size_ > 0) {
            --size_;
            destroy_at(size_);
        }
    }

    // resize
    void resize(size_type new_size, const T& value = T{}) {
        if (new_size > N) throw std::length_error("inplace_vector::resize");
        while (size_ > new_size) pop_back();
        while (size_ < new_size) push_back(value);
    }

    // -----------------------------------------------------------------------
    // Iterators
    // -----------------------------------------------------------------------
    iterator       begin()        noexcept { return data_ptr(); }
    const_iterator begin()  const noexcept { return data_ptr(); }
    const_iterator cbegin() const noexcept { return data_ptr(); }

    iterator       end()        noexcept { return data_ptr() + size_; }
    const_iterator end()  const noexcept { return data_ptr() + size_; }
    const_iterator cend() const noexcept { return data_ptr() + size_; }

    reverse_iterator       rbegin()        noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin()  const noexcept { return const_reverse_iterator(end()); }
    reverse_iterator       rend()          noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend()    const noexcept { return const_reverse_iterator(begin()); }

private:
    // -----------------------------------------------------------------------
    // Internal helpers
    // -----------------------------------------------------------------------

    // Raw pointer to the i-th slot (untyped)
    void* slot(size_type i) noexcept {
        return storage_ + i * sizeof(T);
    }

    // Placement-new: construct a T at slot i using forwarded args
    template <typename... Args>
    void construct_at(size_type i, Args&&... args) {
        ::new (slot(i)) T(std::forward<Args>(args)...);
        //  ^^^^^^^^^^^
        //  "placement new": uses the provided address, no allocation.
        //  T's constructor runs, but no memory is requested from the heap.
    }

    // Explicit destructor call: end the object's lifetime without freeing.
    // This is the ONLY correct way to destroy an object built via placement new.
    void destroy_at(size_type i) noexcept {
        data_ptr()[i].~T();
        //             ^^^
        //  ~T() is called directly on the object. The underlying bytes in
        //  storage_ remain valid; another object can be constructed there later.
    }

    void check_capacity() const {
        if (size_ == N)
            throw std::length_error("inplace_vector: capacity exceeded");
    }
};

// ---------------------------------------------------------------------------
// Equality / comparison
// ---------------------------------------------------------------------------
template <typename T, std::size_t N>
bool operator==(const inplace_vector<T,N>& a, const inplace_vector<T,N>& b) {
    if (a.size() != b.size()) return false;
    for (std::size_t i = 0; i < a.size(); ++i)
        if (!(a[i] == b[i])) return false;
    return true;
}

template <typename T, std::size_t N>
bool operator!=(const inplace_vector<T,N>& a, const inplace_vector<T,N>& b) {
    return !(a == b);
}
