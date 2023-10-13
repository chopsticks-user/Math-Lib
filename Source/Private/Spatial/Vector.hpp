#ifndef MATH_SOURCE_PRIVATE_SPATIAL_VECTOR_HPP
#define MATH_SOURCE_PRIVATE_SPATIAL_VECTOR_HPP

#include "Base/Base.hpp"

namespace Math::Internal::Spatial {

template <I64 nDims> //
class Vector {
public:
private:
  const std::unique_ptr<Real> elements = std::make_unique<Real>(nDims);
};

} // namespace Math::Internal::Spatial

#endif // MATH_SOURCE_PRIVATE_SPATIAL_VECTOR_HPP