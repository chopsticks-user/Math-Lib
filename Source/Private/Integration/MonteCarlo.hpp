#ifndef MATH_PRIVATE_INTEGRATION_MONTECARLO_HPP
#define MATH_PRIVATE_INTEGRATION_MONTECARLO_HPP

#include "Base/Base.hpp"

namespace Math::Internal::Integration {

struct IntBound {
  double lower = 0.0;
  double upper = 0.0;
};

Real monteCarloSimpleImpl(double (*f)(std::vector<double> x),
                          const std::vector<IntBound> &bounds);

} // namespace Math::Internal::Integration

#endif // MATH_PRIVATE_INTEGRATION_MONTECARLO_HPP