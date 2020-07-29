#ifndef MOVIEPRICE_H
#define MOVIEPRICE_H
#include <functional>
#include "imovie.h"

class MoviePrice {
public:
  typedef std::function<int(int)> FrequentPointsCalculator;
  static FrequentPointsCalculator FrequentPointsCalculatorFactory(
      const ReleaseType release_type);

  typedef std::function<double(int)> PriceCalculator;
  static PriceCalculator PriceCalculatorFactory(const ReleaseType release_type);

  static constexpr int MAX_DAYS_RENTED_FOR_CHILDREN = 3;
  static constexpr double DEFAULT_OVERCHARGE_COEFICIENTR = 1.5;
};

#endif // MOVIEPRICE_H
