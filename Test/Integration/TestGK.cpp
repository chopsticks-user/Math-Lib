#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

#include "../../Source/Private/Integration/Integration.hpp"

using Math::Real;
using Math::Internal::Integration::gaussKronrodSimpleImpl;

auto f = [](double x) { return std::sin(std::pow(x, 100)); };

int main(int argc, char **argv) {
  std::cout << std::setprecision(std::numeric_limits<Real>::max_digits10)
            << Math::Internal::Integration::gaussKronrodSimpleImpl(f, 0, 1)
            << '\n';
  return 0;
}