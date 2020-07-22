#ifndef RENTAL_H
#define RENTAL_H

#include <map>
#include "irental.h"

class Rental : IRental {
 public:
  Rental(int days_rented, Movie movie);

  int days_rented() const override;

  Movie movie() const override;

  static Rental createFromLine(const std::string& line,
                               const std::map<int, Movie>& movies);
 private:
  int days_rented_;
  Movie movie_;
};

#endif // RENTAL_H
