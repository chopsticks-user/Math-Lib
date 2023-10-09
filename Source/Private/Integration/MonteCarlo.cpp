#include "MonteCarlo.hpp"

namespace Math::Internal::Integration {

Real monteCarloSimpleImpl(double (*f)(std::vector<double> x),
                          const std::vector<IntBound> &bounds) {
  static constexpr U64 nSamples = 1 << 20;

  if (bounds.size() == 0) {
    throw;
  }

  U64 nVars = bounds.size();
  Real result = 1.0;
  std::vector varSamples(nVars, std::vector<Real>(nSamples));

  for (U64 iVar = 0; iVar < nVars; ++iVar) {
    result *= bounds[iVar].upper - bounds[iVar].lower;
    varSamples[iVar] = std::move(Math::Internal::Base::random(
        bounds[iVar].lower, bounds[iVar].upper, nSamples));
  }

  Real sum = 0.0;
  std::vector<Real> sample(nVars);
  for (U64 iSample = 0; iSample < nSamples; ++iSample) {
    for (U64 iVar = 0; iVar < nVars; ++iVar) {
      sample[iVar] = varSamples[iVar][iSample];
    }
    sum += f(sample);
  }

  return result * sum / nSamples;
}

} // namespace Math::Internal::Integration