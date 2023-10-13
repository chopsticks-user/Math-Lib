#ifndef MATH_PRIVATE_INTEGRATION_GAUSSKRONROD_HPP
#define MATH_PRIVATE_INTEGRATION_GAUSSKRONROD_HPP

#include "Base/Base.hpp"

namespace Math::Internal::Integration {

Real gaussKronrodSimpleImpl(Real (*f)(Real t), Real lowerBound,
                            Real upperBound);

Real gaussKronrodLineImpl(const std::vector<Real (*)(Real t)> &curve,
                          const std::vector<Real> &startPoint,
                          const std::vector<Real> &endPoint);

Real gaussKronrodDoubleImpl();

Real gaussKronrodDoubleTriple();

} // namespace Math::Internal::Integration

#endif // MATH_PRIVATE_INTEGRATION_GAUSSKRONROD_HPP