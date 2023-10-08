#ifndef MATH_PRIVATE_INTEGRATION_GAUSSKRONROD61_HPP
#define MATH_PRIVATE_INTEGRATION_GAUSSKRONROD61_HPP

#include "../Base/Base.hpp"

namespace Math::Internal::Integration {

// F64 gaussKronrodMethod(F64 lowerBound, F64 upperBound, F64 (*f)(F64 x));

F64 gaussKronrodMethod(F64 (*f)(F64 t), F64 lowerBound, F64 upperBound) {
  F64 result = 0.0, scale = (upperBound - lowerBound) / 2.0;
  for (int i = 0; i < Internal::Base::nKronrodPoints; ++i) {
    result += Internal::Base::kronrodWeights[i] *
              f(scale * Internal::Base::kronrodNodes[i] + scale + lowerBound);
  }
  result *= scale;
  return result;
}

} // namespace Math::Internal::Integration

#endif // MATH_PRIVATE_INTEGRATION_GAUSSKRONROD61_HPP