#ifndef IRENTAL_H
#define IRENTAL_H
#include "movie.h"

class IRental {
public:
  virtual int days_rented() const = 0;

  virtual double GetTotalAmount() const = 0;
  virtual double GetFrequentRenterPoints() const = 0;
  virtual const IMovie& movie() const = 0;
};

#endif // IRENTAL_H
