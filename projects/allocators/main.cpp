#include "allocators.hpp"
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

struct JsonValue {
    enum class Kind { Null, Number, String, Array };
    Kind kind = Kind::Null;
    double n  = 0;
    std::pmr::string            s;
    std::pmr::vector<JsonValue> array;

    explicit JsonValue(std::pmr::memory_resource* mr) : s(mr), array(mr) {}

    static JsonValue make_string(std::string_view sv, std::pmr::memory_resource* mr) {
        JsonValue v(mr);
        v.kind = Kind::String;
        v.s.assign(sv.data(), sv.size());
        return v;
    }
    static JsonValue make_number(double val, std::pmr::memory_resource* mr) {
        JsonValue v(mr); v.kind = Kind::Number; v.n = val; return v;
    }
    static JsonValue make_array(std::pmr::memory_resource* mr) {
        JsonValue v(mr); v.kind = Kind::Array; return v;
    }
};

int main() {
    {
        std::cout << "=== LinearAllocator ===\n";
        LinearAllocator arena(64 * 1024);

        std::pmr::vector<std::pmr::string> tokens(&arena);
        tokens.emplace_back("hello");
        tokens.emplace_back("world");
        tokens.emplace_back("from arena");

        std::cout << "used after tokens: " << arena.used() << " bytes\n";
        for (auto& t : tokens) std::cout << "  " << t << "\n";

        JsonValue root = JsonValue::make_array(&arena);
        root.array.push_back(JsonValue::make_string("key",   &arena));
        root.array.push_back(JsonValue::make_number(42.0,    &arena));
        root.array.push_back(JsonValue::make_string("value", &arena));

        std::cout << "used after json tree: " << arena.used() << " bytes\n";
        std::cout << "json array size: " << root.array.size() << "\n";
        arena.release();
        std::cout << "after release: " << arena.used() << " bytes\n\n";
    }
    {
        std::cout << "=== PoolAllocator on LinearAllocator ===\n";
        LinearAllocator arena(64 * 1024);
        PoolAllocator   pool(sizeof(JsonValue), alignof(JsonValue), &arena);

        void* a = pool.allocate(sizeof(JsonValue), alignof(JsonValue));
        void* b = pool.allocate(sizeof(JsonValue), alignof(JsonValue));
        void* c = pool.allocate(sizeof(JsonValue), alignof(JsonValue));

        std::cout << "arena used after 3 allocs: " << arena.used() << "\n";
        pool.deallocate(b, sizeof(JsonValue), alignof(JsonValue));

        void* d = pool.allocate(sizeof(JsonValue), alignof(JsonValue));
        assert(d == b);
        std::cout << "recycled address: " << (d == b ? "yes" : "no") << "\n";
        std::cout << "arena used after recycle (unchanged): " << arena.used() << "\n\n";

        pool.deallocate(a, sizeof(JsonValue), alignof(JsonValue));
        pool.deallocate(c, sizeof(JsonValue), alignof(JsonValue));
        pool.deallocate(d, sizeof(JsonValue), alignof(JsonValue));

        // oversized allocation: bypasses pool, goes directly to arena
        struct BigBlock { char data[256]; };
        static_assert(sizeof(BigBlock) > sizeof(JsonValue), "must be larger than pool block");

        std::size_t before = arena.used();
        void* big = pool.allocate(sizeof(BigBlock), alignof(BigBlock));
        std::cout << "oversized alloc (" << sizeof(BigBlock) << " bytes) bypassed pool\n";
        std::cout << "arena grew by: " << arena.used() - before << " bytes\n";

        pool.deallocate(big, sizeof(BigBlock), alignof(BigBlock));
        std::cout << "oversized dealloc: arena offset unchanged = " << arena.used() << "\n\n";
    }
    {
        std::cout << "=== stdlib monotonic_buffer_resource ===\n";
        std::array<std::byte, 64 * 1024> stack_buf;
        std::pmr::monotonic_buffer_resource stdlib_arena(stack_buf.data(), stack_buf.size());

        std::pmr::vector<std::pmr::string> v(&stdlib_arena);
        v.emplace_back("same api");
        v.emplace_back("different backing");
        for (auto& s : v) std::cout << "  " << s << "\n";
    }
    return 0;
}
