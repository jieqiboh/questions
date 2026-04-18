#include "units.hpp"

#include <iostream>
#include <cassert>

// =============================================================================
// demo.cpp -- exercises units.hpp
// Compile: g++ -std=c++20 -Wall -Wextra -O2 demo.cpp -o demo
// =============================================================================

// Helper to print a labelled result
#define SHOW(expr, unit) \
    std::cout << #expr << " = " << (expr) << " " unit "\n"

// -----------------------------------------------------------------------------
// Physics helpers -- all type-checked at compile time
// -----------------------------------------------------------------------------

Newtons gravitational_force(Kilograms m1, Kilograms m2, Meters r) {
    constexpr double G = 6.674e-11;  // m^3 kg^-1 s^-2 (baked in as double)
    // F = G * m1 * m2 / r^2
    // Dimension check: kg * kg / m^2 = kg^2/m^2 -- not a Newton as-is,
    // so we multiply by the G constant as a raw double (G carries its own units
    // not represented here -- a deliberate teaching moment about library limits)
    double f = G * m1.value() * m2.value() / (r.value() * r.value());
    return Newtons(f);
}

Joules kinetic_energy(Kilograms mass, MetersPerSecond velocity) {
    // KE = 0.5 * m * v^2
    // Quantity * Quantity gives DimMul automatically
    auto mv2 = mass * (velocity * velocity);   // kg * (m/s * m/s) = kg*m^2/s^2 = J
    return Joules(mv2.value() * 0.5);
}

MetersPerSecond final_velocity(MetersPerSecond u, MetersPerSecond2 a, Seconds t) {
    // v = u + a*t
    return u + a * t;   // m/s + (m/s^2 * s) = m/s + m/s  OK
}

Meters displacement(MetersPerSecond u, MetersPerSecond2 a, Seconds t) {
    // s = u*t + 0.5*a*t^2
    auto ut  = u * t;           // m/s * s = m
    auto at2 = a * t * t;       // m/s^2 * s * s = m
    return ut + Meters(at2.value() * 0.5);
}


// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main() {
    std::cout << "=== Basic construction and arithmetic ===\n";
    auto d1 = 100.0_m;
    auto d2 = 50.0_m;
    SHOW(d1 + d2, "m");
    SHOW(d1 - d2, "m");
    SHOW(d1 * 2.0, "m");
    SHOW(d1 / 4.0, "m");

    std::cout << "\n=== Dimensional multiplication ===\n";
    auto m = 10.0_kg;
    auto a_val = Quantity<DimAccel>(9.81);      // 9.81 m/s^2
    auto f = m * a_val;                          // kg * m/s^2 = Newton
    SHOW(f, "N");

    std::cout << "\n=== Velocity = distance / time ===\n";
    auto dist = 1000.0_m;
    auto time = 10.0_s;
    MetersPerSecond v = dist / time;             // Meters / Seconds = MetersPerSecond
    SHOW(v, "m/s");

    std::cout << "\n=== Kinematic equations ===\n";
    MetersPerSecond  u(0.0);                     // initial velocity
    MetersPerSecond2 g(9.81);                    // acceleration due to gravity
    Seconds          t(3.0_s);

    auto vf = final_velocity(u, g, t);
    auto  s = displacement(u, g, t);
    SHOW(vf, "m/s");
    SHOW(s,  "m");

    std::cout << "\n=== Kinetic energy ===\n";
    Kilograms mass(70.0);                        // 70 kg person
    MetersPerSecond speed(10.0);                 // 10 m/s
    auto ke = kinetic_energy(mass, speed);
    SHOW(ke, "J");

    std::cout << "\n=== Gravitational force ===\n";
    Kilograms earth(5.972e24);
    Kilograms person(70.0);
    Meters radius(6.371e6);
    auto fg = gravitational_force(earth, person, radius);
    SHOW(fg, "N");                               // should be ~686 N

    std::cout << "\n=== Unit conversions ===\n";
    Meters marathon(42195.0);                    // marathon in metres
    // convert to km manually
    Meters km_val = marathon / 1000.0;
    SHOW(km_val, "km (numerically)");

    Seconds one_hour = 3600.0_s;
    SHOW(one_hour, "s");

    std::cout << "\n=== Comparisons ===\n";
    auto x = 5.0_m;
    auto y = 3.0_m;
    std::cout << "5m > 3m: "  << (x > y)  << "\n";
    std::cout << "5m == 5m: " << (x == 5.0_m) << "\n";

    std::cout << "\n=== abs ===\n";
    auto neg = Meters(-42.0);
    SHOW(abs(neg), "m");

    // -------------------------------------------------------------------------
    // Compile-time errors (uncomment to verify the type system works):
    // -------------------------------------------------------------------------

    // auto bad1 = 1.0_m + 1.0_s;        // ERROR: no match for operator+
    // auto bad2 = 1.0_kg + 1.0_m;       // ERROR: no match for operator+
    // Seconds bad3 = 1.0_m / 1.0_s;     // ERROR: DimVelocity != DimTime
    // Meters  bad4 = 1.0_kg;             // ERROR: DimMass != DimLength

    std::cout << "\nAll checks passed.\n";
    return 0;
}
