#pragma once

#include <type_traits>
#include <ratio>
#include <ostream>
#include <cmath>

// =============================================================================
// units.hpp -- Type-safe physical units library
//
// Design:
//   Quantity<Dim, T>  -- a scalar of type T tagged with dimension Dim
//   Dim is a Dimension<M, L, T, ...> encoding SI base exponents at compile time
//   Arithmetic enforces dimensional correctness with zero runtime overhead
//
// Concepts demonstrated:
//   - Tag-based type safety (Dimension)
//   - Template non-type parameters
//   - operator overloading with deduced return types
//   - CRTP for named unit types (Meters, Seconds, ...)
//   - constexpr / zero-cost abstractions
//   - std::ratio for unit conversion
// =============================================================================


// -----------------------------------------------------------------------------
// 1. Dimension tag: encodes SI base exponent vector at compile time
//    <Mass, Length, Time, Current, Temperature, Amount, Luminosity>
// -----------------------------------------------------------------------------

template <int M, int L, int Ti, int I = 0, int Th = 0, int N = 0, int J = 0>
struct Dimension {
    static constexpr int mass        = M;
    static constexpr int length      = L;
    static constexpr int time        = Ti;
    static constexpr int current     = I;
    static constexpr int temperature = Th;
    static constexpr int amount      = N;
    static constexpr int luminosity  = J;
};

// Dimension arithmetic (multiply = add exponents, divide = subtract)
template <typename D1, typename D2>
using DimMul = Dimension<
    D1::mass        + D2::mass,
    D1::length      + D2::length,
    D1::time        + D2::time,
    D1::current     + D2::current,
    D1::temperature + D2::temperature,
    D1::amount      + D2::amount,
    D1::luminosity  + D2::luminosity
>;

template <typename D1, typename D2>
using DimDiv = Dimension<
    D1::mass        - D2::mass,
    D1::length      - D2::length,
    D1::time        - D2::time,
    D1::current     - D2::current,
    D1::temperature - D2::temperature,
    D1::amount      - D2::amount,
    D1::luminosity  - D2::luminosity
>;

// Convenience: dimensionless
using Scalar      = Dimension<0, 0, 0>;

// SI base dimensions
using DimMass     = Dimension<1, 0, 0>;
using DimLength   = Dimension<0, 1, 0>;
using DimTime     = Dimension<0, 0, 1>;
using DimCurrent  = Dimension<0, 0, 0, 1>;
using DimTemp     = Dimension<0, 0, 0, 0, 1>;

// Derived dimensions
using DimVelocity     = DimDiv<DimLength, DimTime>;           // m/s
using DimAccel        = DimDiv<DimVelocity, DimTime>;         // m/s^2
using DimForce        = DimMul<DimMass, DimAccel>;            // kg*m/s^2  (Newton)
using DimEnergy       = DimMul<DimForce, DimLength>;          // kg*m^2/s^2 (Joule)
using DimPower        = DimDiv<DimEnergy, DimTime>;           // Watt
using DimArea         = DimMul<DimLength, DimLength>;         // m^2
using DimVolume       = DimMul<DimArea, DimLength>;           // m^3
using DimFrequency    = DimDiv<Scalar, DimTime>;              // 1/s (Hz)
using DimMomentum     = DimMul<DimMass, DimVelocity>;         // kg*m/s


// -----------------------------------------------------------------------------
// 2. Quantity<Dim, T>  -- the core value type
// -----------------------------------------------------------------------------

template <typename Dim, typename T = double>
class Quantity {
public:
    using value_type = T;
    using dim_type   = Dim;

    constexpr Quantity() noexcept : value_(T{}) {}
    constexpr explicit Quantity(T v) noexcept : value_(v) {}

    constexpr T value() const noexcept { return value_; }

    // Unary
    constexpr Quantity operator+() const noexcept { return *this; }
    constexpr Quantity operator-() const noexcept { return Quantity(-value_); }

    // Addition / subtraction -- only same dimension allowed (enforced by type system)
    constexpr Quantity& operator+=(Quantity rhs) noexcept { value_ += rhs.value_; return *this; }
    constexpr Quantity& operator-=(Quantity rhs) noexcept { value_ -= rhs.value_; return *this; }

    // Scaling by dimensionless scalar
    constexpr Quantity& operator*=(T s) noexcept { value_ *= s; return *this; }
    constexpr Quantity& operator/=(T s) noexcept { value_ /= s; return *this; }

    // Comparison (same dimension only)
    constexpr bool operator==(Quantity rhs) const noexcept { return value_ == rhs.value_; }
    constexpr bool operator!=(Quantity rhs) const noexcept { return value_ != rhs.value_; }
    constexpr bool operator< (Quantity rhs) const noexcept { return value_ <  rhs.value_; }
    constexpr bool operator<=(Quantity rhs) const noexcept { return value_ <= rhs.value_; }
    constexpr bool operator> (Quantity rhs) const noexcept { return value_ >  rhs.value_; }
    constexpr bool operator>=(Quantity rhs) const noexcept { return value_ >= rhs.value_; }

private:
    T value_;
};


// -----------------------------------------------------------------------------
// 3. Binary arithmetic -- return type carries the correct dimension
// -----------------------------------------------------------------------------

// Q + Q  (same dim)
template <typename Dim, typename T>
constexpr Quantity<Dim, T> operator+(Quantity<Dim, T> a, Quantity<Dim, T> b) noexcept {
    return Quantity<Dim, T>(a.value() + b.value());
}

// Q - Q  (same dim)
template <typename Dim, typename T>
constexpr Quantity<Dim, T> operator-(Quantity<Dim, T> a, Quantity<Dim, T> b) noexcept {
    return Quantity<Dim, T>(a.value() - b.value());
}

// Q * Q  --> DimMul
template <typename D1, typename D2, typename T>
constexpr Quantity<DimMul<D1, D2>, T> operator*(Quantity<D1, T> a, Quantity<D2, T> b) noexcept {
    return Quantity<DimMul<D1, D2>, T>(a.value() * b.value());
}

// Q / Q  --> DimDiv
template <typename D1, typename D2, typename T>
constexpr Quantity<DimDiv<D1, D2>, T> operator/(Quantity<D1, T> a, Quantity<D2, T> b) noexcept {
    return Quantity<DimDiv<D1, D2>, T>(a.value() / b.value());
}

// Q * scalar
template <typename Dim, typename T>
constexpr Quantity<Dim, T> operator*(Quantity<Dim, T> q, T s) noexcept {
    return Quantity<Dim, T>(q.value() * s);
}
template <typename Dim, typename T>
constexpr Quantity<Dim, T> operator*(T s, Quantity<Dim, T> q) noexcept {
    return Quantity<Dim, T>(s * q.value());
}

// Q / scalar
template <typename Dim, typename T>
constexpr Quantity<Dim, T> operator/(Quantity<Dim, T> q, T s) noexcept {
    return Quantity<Dim, T>(q.value() / s);
}

// scalar / Q  --> negated dimension
template <typename Dim, typename T>
constexpr Quantity<DimDiv<Scalar, Dim>, T> operator/(T s, Quantity<Dim, T> q) noexcept {
    return Quantity<DimDiv<Scalar, Dim>, T>(s / q.value());
}


// -----------------------------------------------------------------------------
// 4. Named unit types via CRTP-style type aliases
//    These are just Quantity specialisations -- no virtual calls, no overhead
// -----------------------------------------------------------------------------

// SI base
using Kilograms   = Quantity<DimMass>;
using Meters      = Quantity<DimLength>;
using Seconds     = Quantity<DimTime>;
using Amperes     = Quantity<DimCurrent>;
using Kelvin      = Quantity<DimTemp>;

// Derived
using MetersPerSecond    = Quantity<DimVelocity>;
using MetersPerSecond2   = Quantity<DimAccel>;
using Newtons            = Quantity<DimForce>;
using Joules             = Quantity<DimEnergy>;
using Watts              = Quantity<DimPower>;
using SquareMeters       = Quantity<DimArea>;
using CubicMeters        = Quantity<DimVolume>;
using Hertz              = Quantity<DimFrequency>;
using NewtonSeconds      = Quantity<DimMomentum>;


// -----------------------------------------------------------------------------
// 5. Unit conversion helpers using std::ratio
//    convert<ToUnit>(from)  -- scales value by Ratio::num / Ratio::den
// -----------------------------------------------------------------------------

template <typename ToUnit, typename Ratio, typename Dim, typename T>
constexpr ToUnit convert(Quantity<Dim, T> q) {
    // Require same dimension (will be a hard error otherwise)
    static_assert(std::is_same_v<Dim, typename ToUnit::dim_type>,
                  "convert: dimension mismatch");
    return ToUnit(static_cast<T>(q.value()) *
                  static_cast<T>(Ratio::num) /
                  static_cast<T>(Ratio::den));
}

// Predefined conversion ratios
using KmToM    = std::ratio<1000, 1>;
using MToKm    = std::ratio<1, 1000>;
using HToS     = std::ratio<3600, 1>;
using SToH     = std::ratio<1, 3600>;
using GToKg    = std::ratio<1, 1000>;
using KgToG    = std::ratio<1000, 1>;

// Convenience wrappers
constexpr Meters    km_to_m(double km)    { return convert<Meters,   KmToM>(Meters(km)); }
constexpr Seconds   hours_to_s(double h)  { return convert<Seconds,  HToS>(Seconds(h)); }


// -----------------------------------------------------------------------------
// 6. User-defined literals for ergonomic construction
// -----------------------------------------------------------------------------

inline namespace units_literals {
    constexpr Kilograms operator""_kg(long double v)        { return Kilograms(static_cast<double>(v)); }
    constexpr Kilograms operator""_kg(unsigned long long v) { return Kilograms(static_cast<double>(v)); }

    constexpr Meters operator""_m(long double v)            { return Meters(static_cast<double>(v)); }
    constexpr Meters operator""_m(unsigned long long v)     { return Meters(static_cast<double>(v)); }

    constexpr Seconds operator""_s(long double v)           { return Seconds(static_cast<double>(v)); }
    constexpr Seconds operator""_s(unsigned long long v)    { return Seconds(static_cast<double>(v)); }

    constexpr Meters operator""_km(long double v)           { return Meters(static_cast<double>(v) * 1000.0); }
    constexpr Meters operator""_km(unsigned long long v)    { return Meters(static_cast<double>(v) * 1000.0); }

    constexpr Newtons operator""_N(long double v)           { return Newtons(static_cast<double>(v)); }
    constexpr Newtons operator""_N(unsigned long long v)    { return Newtons(static_cast<double>(v)); }

    constexpr Joules operator""_J(long double v)            { return Joules(static_cast<double>(v)); }
    constexpr Joules operator""_J(unsigned long long v)     { return Joules(static_cast<double>(v)); }
}


// -----------------------------------------------------------------------------
// 7. ostream support -- prints raw value (attach unit label yourself)
// -----------------------------------------------------------------------------

template <typename Dim, typename T>
std::ostream& operator<<(std::ostream& os, Quantity<Dim, T> q) {
    return os << q.value();
}

// -----------------------------------------------------------------------------
// 8. Concept helper (C++20): check if two Quantities share a dimension
// -----------------------------------------------------------------------------

#if __cplusplus >= 202002L
template <typename Q1, typename Q2>
concept SameDimension = std::is_same_v<typename Q1::dim_type, typename Q2::dim_type>;
#endif


// -----------------------------------------------------------------------------
// 9. Math utilities that preserve dimensions
// -----------------------------------------------------------------------------

// abs
template <typename Dim, typename T>
constexpr Quantity<Dim, T> abs(Quantity<Dim, T> q) noexcept {
    return Quantity<Dim, T>(q.value() < T{} ? -q.value() : q.value());
}

// sqrt  -- halves each exponent (only well-defined for even exponents, user's responsibility)
// Returns a dimensionless double intentionally -- proper sqrt dimension would need
// half-integer exponents which require a more elaborate Dimension type.
// Included to show the limitation and invite extension.
template <typename Dim, typename T>
double sqrt_value(Quantity<Dim, T> q) {
    return std::sqrt(static_cast<double>(q.value()));
}
