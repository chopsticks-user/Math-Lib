#include "Source/Private/Integration/Integration.hpp"
#include "Source/Private/Spatial/Spatial.hpp"

#include <any>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <random>
#include <vector>

using Math::I64;
using Math::Real;
using Math::Internal::Base::Function;
using Math::Internal::Integration::gaussKronrodLineImpl;
using Math::Internal::Integration::IntBound;
using Math::Internal::Spatial::Matrix;
using Math::Internal::Spatial::Tensor;
using Math::Internal::Spatial::Vector;

Real f1(Real x) { return x * x; }
Real f3(Real x) { return x + 1; }

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  std::chrono::high_resolution_clock clock;

  auto c_start = clock.now();

  Function f;
  f = f1;
  Function<Vector<3>, Tensor> g;
  std::cout << f(9.0) << '\n';
  f.set(f3);
  std::cout << f(9.0) << '\n';

  // std::vector<Math::Real (*)(Math::Real t)> functions{f1, f2};
  // std::vector<Math::Real> start{0.0, 0.0}, end{100.0, 21.0};
  // std::cout << std::setprecision(15)
  //           << gaussKronrodLineImpl(functions, start, end) << '\n';

  auto c_end = clock.now();
  std::cout << "Time eslapsed: "
            << static_cast<double>((c_end - c_start).count()) / 1e6 << " ms.\n";

  return 0;
}