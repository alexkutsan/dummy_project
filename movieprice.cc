#include "movieprice.h"
#include <assert.h>

double RegularPrice(int days_rented) {
  if (days_rented > 2)
    return 2 + (days_rented - 2) * MoviePrice::DEFAULT_OVERCHARGE_COEFICIENTR;
  return 2;
}

double NewReleasePrice(int days_rented) {
  return days_rented * 3;
}

double ChildrenPrice(int days_rented) {
  if (days_rented > MoviePrice::MAX_DAYS_RENTED_FOR_CHILDREN)
    return 1.5 + (days_rented - 3) * MoviePrice::DEFAULT_OVERCHARGE_COEFICIENTR;
  return 1.5;
}

int NewReleaseFrequentPoints(const int days_rented) {
  if (days_rented > 1) {
    return 2;
  }
}

int DefaultFrequentPoints(const int days_rented) {
  return 1;
}

MoviePrice::FrequentPointsCalculator
MoviePrice::FrequentPointsCalculatorFactory(const ReleaseType release_type) {
  switch (release_type) {
    case ReleaseType::NEW_RELEASE:
      return FrequentPointsCalculator(NewReleaseFrequentPoints);
    default:
      return FrequentPointsCalculator(DefaultFrequentPoints);
  }
}

MoviePrice::PriceCalculator MoviePrice::PriceCalculatorFactory(
    const ReleaseType release_type) {
  switch (release_type) {
    case ReleaseType::REGULAR:
      return std::function<double(int)>(RegularPrice);
    case ReleaseType::NEW_RELEASE:
      return std::function<double(int)>(NewReleasePrice);
    case ReleaseType::CHILDRENS:
      return std::function<double(int)>(ChildrenPrice);
    default:
      assert(false);
  }
}
