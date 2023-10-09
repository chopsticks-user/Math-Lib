#ifndef MATH_SOURCE_PRIVATE_BASE_UTILITY_RANDOM_HPP
#define MATH_SOURCE_PRIVATE_BASE_UTILITY_RANDOM_HPP

#include "../Def/Def.hpp"

#include <random>

namespace Math::Internal::Base {

Real random(Real start, Real end) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<Real> distrib(start, end);

  return distrib(gen);
}

std::vector<Real> random(Real start, Real end, U64 count) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<Real> distrib(start, end);

  std::vector<Real> rands(count);
  for (auto &r : rands) {
    r = distrib(gen);
  }

  return rands;
}

} // namespace Math::Internal::Base

#endif // MATH_SOURCE_PRIVATE_BASE_UTILITY_RANDOM_HPP