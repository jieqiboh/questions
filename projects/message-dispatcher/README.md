# message-dispatcher

Benchmarks three C++ dispatch strategies on a stream of heterogeneous messages,
motivated by low-latency systems (e.g. trading engines) where dispatch overhead matters.

## Dispatch strategies

| Strategy | Mechanism |
|---|---|
| `std::visit` | Variant + overload pattern; compiler-generated jump table |
| Virtual dispatch | Classic vtable via inheritance (`virtual void handle()`) |
| Hand-rolled vtable | Tagged union + explicit `constexpr` function-pointer array |

## Message types

- `NewOrder` — order id, price, qty, side
- `Cancel` — order id
- `Modify` — order id, new price, new qty

5 million randomly-mixed messages are generated, run through a warmup pass, then timed.
A global `volatile` accumulator prevents the optimizer from eliminating the loops.

## Key concepts

**Overload pattern** — a variadic template that inherits from multiple lambdas and
pulls all their `operator()` overloads into one set via `using Ts::operator()...`.
Paired with CTAD so you can write `overload{f, g, h}` without spelling out types.

**Virtual dispatch cost** — three indirections: load vptr, index vtable, indirect call.
Also scatters objects across the heap (one allocation per message), hurting cache locality.

**Hand-rolled vtable** — same indirection count as virtual, but objects are contiguous
in a `std::vector<RawMessage>` (tagged union), which improves cache behaviour.

## Build & run

```bash
g++ -O2 -std=c++20 -o dispatcher message_dispatcher.cpp
./dispatcher
```

## Results (macOS, Apple M-series, `-O2`)

```
=== Message Dispatcher Benchmark (N=5000000) ===

  std::visit              27.52 ms     5.50 ns/msg
  virtual dispatch        30.07 ms     6.01 ns/msg
  hand-rolled vtable      27.56 ms     5.51 ns/msg
```

`std::visit` and the hand-rolled vtable are essentially identical — the compiler generates
the same jump table either way. Virtual dispatch is ~9% slower, and the bottleneck is not
the vtable lookup itself but **heap fragmentation**: each message is a separate allocation,
so iteration scatters across memory and kills cache locality. The other two strategies store
messages contiguously in a `std::vector`, keeping access patterns cache-friendly.

## About Variant
