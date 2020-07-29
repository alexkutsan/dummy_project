#ifndef IRENTAL_H
#define IRENTAL_H
#include <memory>
#include "movie.h"

class IRental {
 public:
  virtual int days_rented() const = 0;

  virtual double GetTotalAmount() const = 0;
  virtual int GetFrequentRenterPoints() const = 0;
  virtual const IMovie& movie() const = 0;
};

typedef std::unique_ptr<IRental> IRentalPtr;

#endif  // IRENTAL_H
