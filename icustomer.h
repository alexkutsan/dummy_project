#ifndef ICUSTOMER_H
#define ICUSTOMER_H
#include <sstream>
#include <string>
#include "rental.h"

class ICustomer  {
public:
  virtual std::string name() const = 0;

  virtual void AddRental(const Rental& rental) = 0;

  virtual void statement(std::ostringstream& result) = 0;
};
#endif // ICUSTOMER_H
