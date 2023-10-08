#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

#include "../Source/Private/Integration/Integration.hpp"

using Math::F64;

auto f = [](double x) { return std::sin(x * x) * std::exp(3 * x); };

int main(int argc, char **argv) {
  std::cout << std::setprecision(std::numeric_limits<F64>::max_digits10)
            << Math::Internal::Integration::gaussKronrodMethod(f, -5, 2)
            << '\n';
  return 0;
}