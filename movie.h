#ifndef MOVIE_H
#define MOVIE_H
#include <functional>
#include "imovie.h"
#include "movieprice.h"

ReleaseType ReleaseTypeFromString(const std::string& release_type);

class Movie : public IMovie {
 public:
  Movie(const int movie_index,
        const std::string& movie_name,
        const MoviePrice::PriceCalculator& price_calculator,
        const MoviePrice::FrequentPointsCalculator& frequent_points_calculator);

  const std::string& name() const override;

  const int index() const override;

  double GetTotalAmount(const int days_rented) const;
  int GetFrequentRenterPoints(const int days_rented) const;

 private:
  const int index_;
  const std::string name_;
  const MoviePrice::PriceCalculator price_calculator_;
  const MoviePrice::FrequentPointsCalculator frequent_points_calculator_;
};
#endif  // MOVIE_H
