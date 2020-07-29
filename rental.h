#ifndef RENTAL_H
#define RENTAL_H

#include <map>
#include <memory>
#include "irental.h"

class IMovieRepo;
class Rental : public IRental {
 public:
  Rental(int days_rented, const IMovie& movie);

  int days_rented() const override;

  const IMovie& movie() const override;

  double GetTotalAmount() const override;
  int GetFrequentRenterPoints() const override;
  static IRentalPtr createFromLine(const std::string& line,
                                   const IMovieRepo& movies);

 private:
  int days_rented_;
  const IMovie& movie_;
};

#endif  // RENTAL_H
