#ifndef MATH_SOURCE_PRIVATE_BASE_MATH_FUNCTION_HPP
#define MATH_SOURCE_PRIVATE_BASE_MATH_FUNCTION_HPP

#include "Def.hpp"

namespace Math::Internal::Base {

template <typename DomainType = Real, typename CodomainType = Real> //
class Function {
public:
  Function() = default;
  Function(CodomainType (*f)(DomainType)) { function = f; }

  Function set(DomainType (*f)(CodomainType)) {
    function = f;
    return *this;
  }

  DomainType operator()(DomainType t) { return function(t); }

private:
  CodomainType (*function)(DomainType) = [](DomainType) {
    return CodomainType{};
  };
};

} // namespace Math::Internal::Base

#endif // MATH_SOURCE_PRIVATE_BASE_MATH_FUNCTION_HPP