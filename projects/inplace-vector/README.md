# inplace_vector

A fixed-capacity vector backed entirely by stack (or inline) storage. No heap allocation, ever.

## What it demonstrates

- **`alignas` + raw byte storage** — correct alignment for any `T` without default-constructing elements
- **Placement new** — constructing objects in pre-allocated bytes without requesting memory
- **Manual destructor calls** — `obj.~T()` to end object lifetime without freeing anything
- **`std::launder`** — required when reusing storage so the compiler doesn't cache stale pointers
- **Object lifetime rules** — elements exist only between construction and destruction
- **Value semantics** — element-wise copy/move, no allocator machinery

## Files

| File | Purpose |
|------|---------|
| `inplace_vector.hpp` | Header-only implementation |
| `test_inplace_vector.cpp` | Tests covering basic ops, lifetimes, alignment, copy/move |

## Build & run

Requires C++17 (`std::launder`, `_v` trait aliases).

```sh
g++ -std=c++17 -O2 -Wall test_inplace_vector.cpp -o test && ./test
```
