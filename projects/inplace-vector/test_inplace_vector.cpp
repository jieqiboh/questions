#include "inplace_vector.hpp"
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>

// -----------------------------------------------------------
// Instrumented type: prints constructor/destructor calls
// -----------------------------------------------------------
struct Tracked {
    int id;
    static int live;

    explicit Tracked(int id) : id(id) {
        ++live;
        std::cout << "  [ctor]   Tracked(" << id << ")  live=" << live << "\n";
    }
    Tracked(const Tracked& o) : id(o.id) {
        ++live;
        std::cout << "  [copy]   Tracked(" << id << ")  live=" << live << "\n";
    }
    Tracked(Tracked&& o) noexcept : id(o.id) {
        o.id = -1;
        ++live;
        std::cout << "  [move]   Tracked(" << id << ")  live=" << live << "\n";
    }
    ~Tracked() {
        --live;
        std::cout << "  [dtor]   Tracked(" << id << ")  live=" << live << "\n";
    }
};
int Tracked::live = 0;

// -----------------------------------------------------------
// Tests
// -----------------------------------------------------------
void test_basic() {
    std::cout << "\n=== test_basic ===\n";
    inplace_vector<int, 8> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    assert(v.size() == 3);
    assert(v[0] == 10 && v[1] == 20 && v[2] == 30);
    v.pop_back();
    assert(v.size() == 2 && v.back() == 20);
    std::cout << "PASS\n";
}

void test_lifetime() {
    std::cout << "\n=== test_lifetime (Tracked) ===\n";
    {
        inplace_vector<Tracked, 4> v;
        v.emplace_back(1);
        v.emplace_back(2);
        v.emplace_back(3);
        assert(Tracked::live == 3);
        v.pop_back();
        assert(Tracked::live == 2);
    } // destructor fires here, should reach live == 0
    assert(Tracked::live == 0);
    std::cout << "PASS (no leaks)\n";
}

void test_capacity_exceeded() {
    std::cout << "\n=== test_capacity_exceeded ===\n";
    inplace_vector<int, 3> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    try {
        v.push_back(4);
        assert(false && "should have thrown");
    } catch (const std::length_error& e) {
        std::cout << "Caught expected: " << e.what() << "\nPASS\n";
    }
}

void test_copy_move() {
    std::cout << "\n=== test_copy_move ===\n";
    inplace_vector<std::string, 4> a;
    a.push_back("hello");
    a.push_back("world");

    auto b = a;                      // copy
    assert(b[0] == "hello");

    auto c = std::move(b);           // move
    assert(c[0] == "hello");
    assert(b.empty());               // source cleared

    std::cout << "PASS\n";
}

void test_alignment() {
    std::cout << "\n=== test_alignment ===\n";
    // All 16-byte aligned type
    struct alignas(16) Vec4 { float x, y, z, w; };
    inplace_vector<Vec4, 8> v;
    v.emplace_back(Vec4{1,2,3,4});
    uintptr_t addr = reinterpret_cast<uintptr_t>(&v[0]);
    assert(addr % alignof(Vec4) == 0);
    std::cout << "Address of v[0]: 0x" << std::hex << addr
              << " (aligned to " << std::dec << alignof(Vec4) << " bytes)\n";
    std::cout << "PASS\n";
}

void test_no_heap() {
    // sizeof(inplace_vector<int,N>) should be exactly N*sizeof(int) + sizeof(size_t)
    // i.e. no pointer to heap-allocated buffer
    std::cout << "\n=== test_no_heap ===\n";
    constexpr std::size_t expected = 8 * sizeof(int) + sizeof(std::size_t);
    std::cout << "sizeof(inplace_vector<int,8>) = "
              << sizeof(inplace_vector<int, 8>) << "\n";
    // Padding may add a few bytes, but there must be no heap pointer (8 bytes extra)
    static_assert(sizeof(inplace_vector<int, 8>) <= expected + 8,
                  "unexpectedly large: likely an internal heap pointer");
    std::cout << "PASS\n";
}

void test_initializer_list() {
    std::cout << "\n=== test_initializer_list ===\n";
    inplace_vector<int, 8> v = {3, 1, 4, 1, 5};
    assert(v.size() == 5);
    assert(v[2] == 4);
    std::cout << "PASS\n";
}

int main() {
    test_basic();
    test_lifetime();
    test_capacity_exceeded();
    test_copy_move();
    test_alignment();
    test_no_heap();
    test_initializer_list();

    std::cout << "\nAll tests passed.\n";
}
