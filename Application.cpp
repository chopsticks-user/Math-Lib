#include "Source/Private/Integration/Integration.hpp"

#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using Math::Internal::Integration::gaussKronrodLineImpl;
using Math::Internal::Integration::IntBound;

auto f1 = [](Math::Real x) { return x + 1; };
auto f2 = [](Math::Real y) { return y + 1; };

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::chrono::high_resolution_clock clock;

  auto c_start = clock.now();

  std::vector<Math::Real (*)(Math::Real t)> functions{f1, f2};
  std::vector<Math::Real> start{0.0, 0.0}, end{100.0, 21.0};
  std::cout << std::setprecision(15)
            << gaussKronrodLineImpl(functions, start, end) << '\n';

  auto c_end = clock.now();
  std::cout << "Time eslapsed: "
            << static_cast<double>((c_end - c_start).count()) / 1e6 << " ms.\n";

  return 0;
}