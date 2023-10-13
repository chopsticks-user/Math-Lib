#ifndef MATH_SOURCE_PRIVATE_SPATIAL_MATRIX_HPP
#define MATH_SOURCE_PRIVATE_SPATIAL_MATRIX_HPP

#include "Base/Base.hpp"

namespace Math::Internal::Spatial {

template <I64 nRows, I64 nCols> //
class Matrix {
public:
private:
  const std::unique_ptr<Real> elements = std::make_unique<Real>(nRows * nCols);
};

} // namespace Math::Internal::Spatial

#endif // MATH_SOURCE_PRIVATE_SPATIAL_MATRIX_HPP