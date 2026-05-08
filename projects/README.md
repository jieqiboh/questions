Tier 1 – Core Language Mastery
1. Type-safe units library
Build Quantity<Tag, T> so Meters and Seconds are incompatible at compile time. Teaches templates, operator overloading, CRTP, zero-cost abstractions.
2. unique_ptr from scratch
Implement move semantics, custom deleters, EBO for zero-size deleters, make_unique. You already have context here – push it to array specialization and release()/reset() edge cases.
3. inplace_vector<T, N>
Fixed-capacity vector with aligned storage (std::aligned_storage or alignas), placement new, manual destructor calls. Teaches object lifetime, alignment, and why HFT avoids heap.

Tier 2 – Performance Primitives
4. SPSC ring buffer (lock-free)
Single-producer single-consumer queue using std::atomic with explicit memory orderings (acquire/release). Benchmark with rdtsc. You’ve done this in Rust – the C++ version forces you to reason about the memory model more carefully.
5. PMR arena allocator
The JSON parser project above, but then extract the arena into a reusable LinearAllocator that satisfies std::pmr::memory_resource. Add a pool on top.
6. Cache-line aware data structures
Implement a struct-of-arrays order book side (bids/asks as separate price/qty arrays). Measure false sharing with perf or cachegrind. Add alignas(64) and observe.

Tier 3 – HFT Primitives
7. Order book with price-level aggregation
std::map<Price, Level> first, then replace with a flat sorted array + binary search, then a Fenwick tree for O(log n) prefix queries. Profile each. This directly mirrors interview problems at trading firms.
8. variant-based message dispatcher
Model fix-like messages as std::variant<NewOrder, Cancel, Modify>. Use std::visit with overload pattern. Then hand-roll the vtable to understand the overhead. Compare std::visit vs virtual dispatch vs function pointer tables via benchmarks.
9. Compile-time FIX message schema
Use constexpr and templates to define FIX tag mappings at compile time. Parse a FIX string into a strongly-typed struct with zero runtime overhead for field lookup. This is directly what low-latency feed handlers do.

Tier 4 – Systems-Level C++
10. Custom std::function without heap
Implement small-buffer-optimized callable wrapper. No heap allocation for small lambdas. Teaches SBO, type erasure, alignment tricks, and why std::function is banned in hot paths.
11. Coroutine-based async I/O
Use C++20 coroutines to build a minimal async TCP client. Implement Awaitable types manually (don’t use a framework). This teaches the coroutine machinery that underpins modern async networking stacks.
12. mmap-based shared memory IPC
Producer process writes market data into a shared memory region. Consumer reads with no syscalls in the hot path. Add a sequence lock (seqlock) for concurrent access without mutexes. This is how real tick-to-trade pipelines work.

Tier 5 – Compiler and Binary Level
13. CRTP policy-based order router
Build a router where execution venue, risk check, and logging are all compile-time policies injected via CRTP. No virtual calls anywhere. Study the generated assembly with godbolt.org.
14. Profile-guided optimization experiment
Take your order book from project 7. Compile with -fprofile-generate, run a realistic workload, recompile with -fprofile-use. Measure the difference. Then try BOLT on the binary. This is directly relevant to your LLVM work.
15. Custom memory-mapped tick store
Write a binary log format for tick data. Append-only, mmap-backed, with a reader that can tail it without locking. Add a header with magic bytes and schema version. This is a realistic component from any market data pipeline.
