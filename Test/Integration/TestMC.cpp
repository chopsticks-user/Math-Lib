#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

#include "../../Source/Private/Integration/Integration.hpp"

using Math::Internal::Integration::IntBound;
using Math::Internal::Integration::monteCarloSimpleImpl;

auto f = [](std::vector<double> x) {
  double sum = 0.0;
  for (auto xi : x) {
    sum += xi;
  }
  return sum * sum;
};

int main(int argc, char **argv) {
  std::chrono::high_resolution_clock clock;

  auto c_start = clock.now();

  std::vector<IntBound> bounds{{26, -9}, {0, 1}, {-1, 1}};
  std::cout << std::setprecision(15) << monteCarloSimpleImpl(f, bounds) << '\n';

  auto c_end = clock.now();
  std::cout << "Time eslapsed: " << (c_end - c_start).count() / 1e6 << " ms.\n";

  return 0;
}