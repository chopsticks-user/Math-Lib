#ifndef MATH_PRIVATE_INTEGRATION_GAUSSKRONROD_HPP
#define MATH_PRIVATE_INTEGRATION_GAUSSKRONROD_HPP

#include "../Base/Base.hpp"

namespace Math::Internal::Integration {

// Real gaussKronrodMethod(Real lowerBound, Real upperBound, Real (*f)(Real x));

constexpr I64 nKronrodPoints = 61;

const std::vector<Real> kronrodNodes{0.0,
                                    5.147184255531769583302521316672257e-02,
                                    1.028069379667370301470967513180006e-01,
                                    1.538699136085835469637946727432559e-01,
                                    2.045251166823098914389576710020247e-01,
                                    2.546369261678898464398051298178051e-01,
                                    3.040732022736250773726771071992566e-01,
                                    3.527047255308781134710372070893739e-01,
                                    4.004012548303943925354762115426606e-01,
                                    4.470337695380891767806099003228540e-01,
                                    4.924804678617785749936930612077088e-01,
                                    5.366241481420198992641697933110728e-01,
                                    5.793452358263616917560249321725405e-01,
                                    6.205261829892428611404775564311893e-01,
                                    6.600610641266269613700536681492708e-01,
                                    6.978504947933157969322923880266401e-01,
                                    7.337900624532268047261711313695276e-01,
                                    7.677774321048261949179773409745031e-01,
                                    7.997278358218390830136689423226832e-01,
                                    8.295657623827683974428981197325019e-01,
                                    8.572052335460610989586585106589439e-01,
                                    8.825605357920526815431164625302256e-01,
                                    9.055733076999077985465225589259583e-01,
                                    9.262000474292743258793242770804740e-01,
                                    9.443744447485599794158313240374391e-01,
                                    9.600218649683075122168710255817977e-01,
                                    9.731163225011262683746938684237069e-01,
                                    9.836681232797472099700325816056628e-01,
                                    9.916309968704045948586283661094857e-01,
                                    9.968934840746495402716300509186953e-01,
                                    9.994844100504906375713258957058108e-01,
                                    -5.147184255531769583302521316672257e-02,
                                    -1.028069379667370301470967513180006e-01,
                                    -1.538699136085835469637946727432559e-01,
                                    -2.045251166823098914389576710020247e-01,
                                    -2.546369261678898464398051298178051e-01,
                                    -3.040732022736250773726771071992566e-01,
                                    -3.527047255308781134710372070893739e-01,
                                    -4.004012548303943925354762115426606e-01,
                                    -4.470337695380891767806099003228540e-01,
                                    -4.924804678617785749936930612077088e-01,
                                    -5.366241481420198992641697933110728e-01,
                                    -5.793452358263616917560249321725405e-01,
                                    -6.205261829892428611404775564311893e-01,
                                    -6.600610641266269613700536681492708e-01,
                                    -6.978504947933157969322923880266401e-01,
                                    -7.337900624532268047261711313695276e-01,
                                    -7.677774321048261949179773409745031e-01,
                                    -7.997278358218390830136689423226832e-01,
                                    -8.295657623827683974428981197325019e-01,
                                    -8.572052335460610989586585106589439e-01,
                                    -8.825605357920526815431164625302256e-01,
                                    -9.055733076999077985465225589259583e-01,
                                    -9.262000474292743258793242770804740e-01,
                                    -9.443744447485599794158313240374391e-01,
                                    -9.600218649683075122168710255817977e-01,
                                    -9.731163225011262683746938684237069e-01,
                                    -9.836681232797472099700325816056628e-01,
                                    -9.916309968704045948586283661094857e-01,
                                    -9.968934840746495402716300509186953e-01,
                                    -9.994844100504906375713258957058108e-01};

const std::vector<Real> kronrodWeights{5.149472942945156755834043364709931e-02,
                                      5.142612853745902593386287921578126e-02,
                                      5.122154784925877217065628260494421e-02,
                                      5.088179589874960649229747304980469e-02,
                                      5.040592140278234684089308565358503e-02,
                                      4.979568342707420635781156937994233e-02,
                                      4.905543455502977888752816536723817e-02,
                                      4.818586175708712914077949229830459e-02,
                                      4.718554656929915394526147818109949e-02,
                                      4.605923827100698811627173555937358e-02,
                                      4.481480013316266319235555161672324e-02,
                                      4.345253970135606931683172811707326e-02,
                                      4.196981021516424614714754128596976e-02,
                                      4.037453895153595911199527975246811e-02,
                                      3.867894562472759295034865153228105e-02,
                                      3.688236465182122922391106561713597e-02,
                                      3.497933802806002413749967073146788e-02,
                                      3.298144705748372603181419101685393e-02,
                                      3.090725756238776247288425294309227e-02,
                                      2.875404876504129284397878535433421e-02,
                                      2.650995488233310161060170933507541e-02,
                                      2.419116207808060136568637072523203e-02,
                                      2.182803582160919229716748573833899e-02,
                                      1.941414119394238117340895105012846e-02,
                                      1.692088918905327262757228942032209e-02,
                                      1.436972950704580481245143244358001e-02,
                                      1.182301525349634174223289885325059e-02,
                                      9.273279659517763428441146892024360e-03,
                                      6.630703915931292173319826369750168e-03,
                                      3.890461127099884051267201844515503e-03,
                                      1.389013698677007624551591226759700e-03,
                                      5.142612853745902593386287921578126e-02,
                                      5.122154784925877217065628260494421e-02,
                                      5.088179589874960649229747304980469e-02,
                                      5.040592140278234684089308565358503e-02,
                                      4.979568342707420635781156937994233e-02,
                                      4.905543455502977888752816536723817e-02,
                                      4.818586175708712914077949229830459e-02,
                                      4.718554656929915394526147818109949e-02,
                                      4.605923827100698811627173555937358e-02,
                                      4.481480013316266319235555161672324e-02,
                                      4.345253970135606931683172811707326e-02,
                                      4.196981021516424614714754128596976e-02,
                                      4.037453895153595911199527975246811e-02,
                                      3.867894562472759295034865153228105e-02,
                                      3.688236465182122922391106561713597e-02,
                                      3.497933802806002413749967073146788e-02,
                                      3.298144705748372603181419101685393e-02,
                                      3.090725756238776247288425294309227e-02,
                                      2.875404876504129284397878535433421e-02,
                                      2.650995488233310161060170933507541e-02,
                                      2.419116207808060136568637072523203e-02,
                                      2.182803582160919229716748573833899e-02,
                                      1.941414119394238117340895105012846e-02,
                                      1.692088918905327262757228942032209e-02,
                                      1.436972950704580481245143244358001e-02,
                                      1.182301525349634174223289885325059e-02,
                                      9.273279659517763428441146892024360e-03,
                                      6.630703915931292173319826369750168e-03,
                                      3.890461127099884051267201844515503e-03,
                                      1.389013698677007624551591226759700e-03};

Real gaussKronrodSimpleImpl(Real (*f)(Real t), Real lowerBound, Real upperBound) {
  if (lowerBound == upperBound) {
    return 0.0;
  }

  Real result = 0.0, scale = (upperBound - lowerBound) / 2.0;
  for (int i = 0; i < nKronrodPoints; ++i) {
    result +=
        kronrodWeights[i] * f(scale * kronrodNodes[i] + scale + lowerBound);
  }
  return result * scale;
}

} // namespace Math::Internal::Integration

#endif // MATH_PRIVATE_INTEGRATION_GAUSSKRONROD_HPP