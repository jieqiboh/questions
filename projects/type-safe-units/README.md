# Type-Safe Units Library

A header-only C++ library that makes mixing incompatible physical units a **compile-time error** — not a runtime crash.

```cpp
Meters  d = 100.0_m;
Seconds t = 10.0_s;

MetersPerSecond v = d / t;    // OK: m / s = m/s
auto bad = d + t;             // ERROR: no match for operator+
```

Zero runtime overhead. The dimension system lives entirely in the type system.

---

## Concepts Taught

| Concept | Where |
|---------|-------|
| Non-type template parameters | `Dimension<M, L, Ti, ...>` |
| Template type aliases (`using`) | `DimMul`, `DimDiv`, named units |
| Operator overloading with deduced return types | `operator*`, `operator/` |
| `constexpr` / zero-cost abstractions | All `Quantity` methods |
| User-defined literals | `1.0_m`, `9.81_kg`, `3.0_s` |
| `std::ratio` for unit conversion | `convert<>`, `KmToM`, `HToS` |
| C++20 concepts | `SameDimension` |

---

## Files

```
type-safe-units/
├── units.hpp   # The library — single header, no dependencies beyond the STL
└── demo.cpp    # Worked examples: kinematics, energy, gravity, conversions
```

---

## How to Run

### Requirements

- A C++20-capable compiler: `g++ 10+` or `clang++ 12+`
- No external dependencies

### Build and run

```bash
# From inside the type-safe-units/ directory:
g++ -std=c++20 -Wall -Wextra -O2 demo.cpp -o demo
./demo
```

Or with clang:

```bash
clang++ -std=c++20 -Wall -Wextra -O2 demo.cpp -o demo
./demo
```

### Expected output

```
=== Basic construction and arithmetic ===
d1 + d2 = 150 m
d1 - d2 = 50 m
d1 * 2.0 = 200 m
d1 / 4.0 = 25 m

=== Dimensional multiplication ===
f = 98.1 N

=== Velocity = distance / time ===
v = 100 m/s

=== Kinematic equations ===
vf = 29.43 m/s
s = 44.145 m

=== Kinetic energy ===
ke = 3500 J

=== Gravitational force ===
fg = 685.858 N

=== Unit conversions ===
km_val = 42.195 km (numerically)
one_hour = 3600 s

=== Comparisons ===
5m > 3m: 1
5m == 5m: 1

=== abs ===
abs(neg) = 42 m

All checks passed.
```

---

## Verify the type system

At the bottom of `demo.cpp` there are four commented-out lines that **should not compile**. Uncomment them one at a time and observe the error:

```cpp
auto bad1 = 1.0_m + 1.0_s;     // ERROR: metres + seconds
auto bad2 = 1.0_kg + 1.0_m;    // ERROR: kilograms + metres
Seconds bad3 = 1.0_m / 1.0_s;  // ERROR: velocity assigned to time
Meters  bad4 = 1.0_kg;          // ERROR: mass assigned to length
```

The compiler error will point to the exact line — no runtime debugging needed.

---

## Architecture

```
Dimension<M, L, Ti, I, Th, N, J>
    └─ 7 int non-type template params = SI base exponents
    └─ DimMul<D1,D2>  adds exponents   (physical multiplication)
    └─ DimDiv<D1,D2>  subtracts exponents (physical division)

Quantity<Dim, T>
    └─ wraps a single value of type T
    └─ operator* returns Quantity<DimMul<D1,D2>>
    └─ operator/ returns Quantity<DimDiv<D1,D2>>
    └─ operator+ only exists for matching Dim (enforced by overload resolution)

Named aliases (zero overhead, just readability):
    Meters      = Quantity<DimLength>
    Seconds     = Quantity<DimTime>
    Newtons     = Quantity<DimForce>   // = Quantity<Dimension<1,1,-2>>
    ...
```

---

## Extension Ideas

- **Half-integer exponents** — replace `int` params with `std::ratio` to support `sqrt` with proper dimensions
- **Unit scaling layer** — add `Unit<Quantity, Ratio, Symbol>` for km, miles, kPa with `convert<>` enforcement
- **Benchmark zero-cost** — compare `-O0` vs `-O2` assembly with `godbolt.org` to confirm no overhead
- **Affine types** — extend for Celsius/Fahrenheit where addition is not always meaningful
