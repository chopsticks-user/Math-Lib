#ifndef MATH_SOURCE_PRIVATE_BASE_UTILITY_RANDOM_HPP
#define MATH_SOURCE_PRIVATE_BASE_UTILITY_RANDOM_HPP

#include "Platform.hpp"
#include "Typename.hpp"

namespace Math::Internal::Base {

Real random(Real start, Real end);

std::vector<Real> random(Real start, Real end, U64 count);

} // namespace Math::Internal::Base

#endif // MATH_SOURCE_PRIVATE_BASE_UTILITY_RANDOM_HPP