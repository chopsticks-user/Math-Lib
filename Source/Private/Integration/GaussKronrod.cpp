#include "GaussKronrod.hpp"

namespace Math::Internal::Integration {

Real gaussKronrodSimpleImpl(Real (*f)(Real t), Real lowerBound, Real upperBound) {
  Real result = 0.0, scale = (upperBound - lowerBound) / 2.0;
  for (int i = 0; i < Internal::Base::nKronrodPoints; ++i) {
    result += Internal::Base::kronrodWeights[i] *
              f(scale * Internal::Base::kronrodNodes[i] + scale + lowerBound);
  }
  result *= scale;
  return result;
}

} // namespace Math::Internal::Integration