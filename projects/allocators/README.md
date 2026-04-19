# allocators

Two custom allocators implementing the `std::pmr::memory_resource` interface, demonstrated with a PMR-aware JSON value tree.

## Allocators

**`LinearAllocator`** — arena/bump allocator. Allocates by advancing an offset into a contiguous buffer. Individual deallocations are no-ops; the whole arena is released at once with `release()`. O(1) allocation, zero fragmentation.

**`PoolAllocator`** — fixed-block pool allocator. Allocates same-sized blocks from a free list. Deallocated blocks are returned to the list and reused on the next allocation rather than going back to the upstream resource. O(1) alloc and dealloc.

## Key concepts

- `std::pmr::memory_resource` — the standard polymorphic allocator interface
- Upstream chaining — `PoolAllocator` delegates to `LinearAllocator` for fresh blocks
- Free list — intrusive singly-linked list stored inside the free blocks themselves
- `std::align` — advances a pointer to satisfy an alignment requirement
- `std::pmr::polymorphic_allocator` — stateful allocator that stores a `memory_resource*`; costs 8 extra bytes per container vs stateless `std::allocator`

## std::vector vs std::pmr::vector size

```
std::vector<T>:       24 bytes  (begin* + end* + capacity*)
std::pmr::vector<T>:  32 bytes  (+ memory_resource* to remember which arena)
```

`std::allocator` is stateless — all instances behave identically (always call `::operator new`), so nothing needs to be stored and the compiler eliminates it via EBO. `std::pmr::polymorphic_allocator` is stateful — two instances can back different arenas, so the pointer must be stored.

## Files

| File | Purpose |
|------|---------|
| `allocators.hpp` | `LinearAllocator` and `PoolAllocator` implementations |
| `main.cpp` | Demo: arena with PMR containers, pool on top of arena, stdlib comparison |

## Memory usage walkthrough

Expected output: `used after tokens: 224 bytes`, `used after json tree: 784 bytes`.

**tokens (224 bytes)**

`sizeof(std::pmr::string) = 32`. Three `emplace_back` calls trigger two vector resizes:
```
alloc 1 × 32 =  32 bytes  (abandoned, LinearAllocator can't free)
alloc 2 × 32 =  64 bytes  (abandoned)
alloc 4 × 32 = 128 bytes  (current)
               224 bytes total
```
"hello", "world", "from arena" are ≤15 chars → SSO, no extra string allocations.

**sizeof(JsonValue) = 80 bytes**
```
Kind (int):          4 bytes  alignof=4
padding:             4 bytes  (to reach alignof=8 for double)
double n:            8 bytes  alignof=8
pmr::string s:      32 bytes  alignof=8  (offset=16, already aligned)
pmr::vector array:  32 bytes  alignof=8  (offset=48, already aligned)
                    ────────
                    80 bytes
```
`pmr::vector` is 32 bytes: 3 pointers (begin/end/capacity=24) + `memory_resource*` (8).

**json tree (560 bytes)**

Three `push_back` calls on `root.array` trigger two vector resizes:
```
push_back("key")   → alloc 1 × 80 =  80 bytes  (abandoned)
push_back(42.0)    → alloc 2 × 80 = 160 bytes  (abandoned)
push_back("value") → alloc 4 × 80 = 320 bytes  (current)
                                    560 bytes total
```
"key" and "value" fit SSO. Nested fields inside each stored `JsonValue` are empty → no further allocations.

**Total: 224 + 560 = 784 bytes**

## Pool allocator walkthrough

**3 normal allocs (240 bytes)**
```
pool.allocate(80, 8) → free list empty → arena: 0   → 80   (A)
pool.allocate(80, 8) → free list empty → arena: 80  → 160  (B)
pool.allocate(80, 8) → free list empty → arena: 160 → 240  (C)
```

**Free B, alloc D — arena unchanged**
```
deallocate(B) → push B onto free list → free_list_: B → nullptr
allocate(80)  → pop B from free list  → return B as D
arena offset: still 240
```
`d == b` — the same address is recycled without touching the arena.

**Free A, C, D — arena unchanged**
```
deallocate(A) → free_list_: A → nullptr
deallocate(C) → free_list_: C → A → nullptr
deallocate(D) → free_list_: D → C → A → nullptr
arena offset: still 240
```

**Oversized alloc (256 bytes > block_size_ 80)**
```
pool.allocate(256, 1) → 256 > block_size_ → bypass pool → ask arena directly
arena: 240 → 496

pool.deallocate(big, 256, 1) → 256 > block_size_ → bypass pool → arena.do_deallocate() → no-op
arena offset: still 496  ← 256 bytes permanently abandoned
```

Abandonment here is not a deliberate decision — it is a consequence of `LinearAllocator::do_deallocate` being a no-op. If the upstream were the heap, oversized frees would be returned normally. The arena trades individual-free capability for speed; the accepted usage pattern is allocate → use → `release()` everything at once. To avoid abandonment, either size the pool large enough, use multiple pools of different sizes, or use the heap as upstream for oversized allocations.

## How free blocks are reused

When a block is deallocated, its first bytes are overwritten with a `FreeNode*` pointer linking it into the free list. The rest of the bytes are untouched. On the next allocation, the new object overwrites all 80 bytes.

```
in use:      [ JsonValue data (80 bytes)          ]
after free:  [ FreeNode* | remaining bytes        ]
              ^^^^^^^^^^^ only first bytes stomped
after reuse: [ new JsonValue data (80 bytes)      ]
```

This is why use-after-free is silent and dangerous — the bytes are still readable after `deallocate`, just partially overwritten by the free list pointer. After the next allocation hands that block out, reading the old pointer gives you the new object's data with no crash or warning.

## Build & run

Requires C++17.

```sh
g++ -std=c++17 -O2 -Wall main.cpp -o allocators && ./allocators
```
