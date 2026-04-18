#pragma once
#include <memory>
#include <utility>

// ── Primary template (single object) ─────────────────────────────────────────

template <typename T, typename Deleter = std::default_delete<T>>
class unique_ptr {
private:
    T* ptr_ = nullptr;
    [[no_unique_address]] Deleter deleter_;

public:
    using pointer      = T*;
    using element_type = T;
    using deleter_type = Deleter;

    unique_ptr() noexcept = default;
    explicit unique_ptr(T* p) noexcept : ptr_(p) {}

    unique_ptr(T* p, const Deleter& d) noexcept : ptr_(p), deleter_(d) {}
    unique_ptr(T* p, Deleter&& d)      noexcept : ptr_(p), deleter_(std::move(d)) {}

    ~unique_ptr() noexcept { reset(); }

    unique_ptr(const unique_ptr&)            = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& other) noexcept
        : ptr_(other.release()), deleter_(std::move(other.deleter_)) {}

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            reset(other.release());
            deleter_ = std::move(other.deleter_);
        }
        return *this;
    }

    unique_ptr& operator=(std::nullptr_t) noexcept {
        reset();
        return *this;
    }

    T* get()                    const noexcept { return ptr_; }
    Deleter&       get_deleter()      noexcept { return deleter_; }
    const Deleter& get_deleter()const noexcept { return deleter_; }
    explicit operator bool()    const noexcept { return ptr_ != nullptr; }

    T& operator*()  const noexcept { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }

    T* release() noexcept { return std::exchange(ptr_, nullptr); }

    void reset(T* p = nullptr) noexcept {
        T* old = std::exchange(ptr_, p);
        if (old) deleter_(old);
    }

    void swap(unique_ptr& other) noexcept {
        std::swap(ptr_, other.ptr_);
        std::swap(deleter_, other.deleter_);
    }
};

// ── Array specialization ──────────────────────────────────────────────────────

template <typename T, typename Deleter>
class unique_ptr<T[], Deleter> {
private:
    T* ptr_ = nullptr;
    [[no_unique_address]] Deleter deleter_;

public:
    using pointer      = T*;
    using element_type = T;
    using deleter_type = Deleter;

    unique_ptr() noexcept = default;

    // Only accept T* exactly — blocks unsafe derived-to-base array conversions
    template <typename U>
    explicit unique_ptr(U p) noexcept
        requires std::same_as<U, T*>
        : ptr_(p) {}

    ~unique_ptr() noexcept { reset(); }

    unique_ptr(const unique_ptr&)            = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& other) noexcept
        : ptr_(other.release()), deleter_(std::move(other.deleter_)) {}

    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            reset(other.release());
            deleter_ = std::move(other.deleter_);
        }
        return *this;
    }

    T& operator[](std::size_t i) const noexcept { return ptr_[i]; }

    T* get()                    const noexcept { return ptr_; }
    Deleter&       get_deleter()      noexcept { return deleter_; }
    const Deleter& get_deleter()const noexcept { return deleter_; }
    explicit operator bool()    const noexcept { return ptr_ != nullptr; }

    T* release() noexcept { return std::exchange(ptr_, nullptr); }

    void reset(T* p = nullptr) noexcept {
        T* old = std::exchange(ptr_, p);
        if (old) deleter_(old);
    }

    void swap(unique_ptr& other) noexcept {
        std::swap(ptr_, other.ptr_);
        std::swap(deleter_, other.deleter_);
    }
};

// ── make_unique ───────────────────────────────────────────────────────────────

// Single object
template <typename T, typename... Args>
    requires (!std::is_array_v<T>)
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// Unbounded array (T = U[])
template <typename T>
    requires std::is_unbounded_array_v<T>
unique_ptr<T> make_unique(std::size_t n) {
    using U = std::remove_extent_t<T>;
    return unique_ptr<T>(new U[n]());
}

// Bounded array (T = U[N]) — explicitly deleted
template <typename T, typename... Args>
    requires std::is_bounded_array_v<T>
void make_unique(Args&&...) = delete;
