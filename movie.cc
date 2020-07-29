#include "movie.h"
#include <assert.h>
#include <memory>
#include <vector>

Movie::Movie(
    const int movie_index,
    const std::string& movie_name,
    const MoviePrice::PriceCalculator& price_calculator,
    const MoviePrice::FrequentPointsCalculator& frequent_points_calculator)
    : index_(movie_index)
    , name_(movie_name)
    // Make class real for Price calculator instead of 2 lambdas
    , price_calculator_(price_calculator)
    , frequent_points_calculator_(frequent_points_calculator) {}

const std::string& Movie::name() const {
  return name_;
}

const int Movie::index() const {
  return index_;
}

double Movie::GetTotalAmount(const int days_rented) const {
  return price_calculator_(days_rented);
}

int Movie::GetFrequentRenterPoints(const int days_rented) const {
  frequent_points_calculator_(days_rented);
}

ReleaseType ReleaseTypeFromString(const std::string& release_type) {
  static std::unordered_map<std::string, ReleaseType> convertion_map = {
      {"REGULAR", ReleaseType::REGULAR},
      {"NEW_RELEASE", ReleaseType::NEW_RELEASE},
      {"CHILDRENS", ReleaseType::CHILDRENS},
  };
  return convertion_map.at(release_type);
}
