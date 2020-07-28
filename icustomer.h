#ifndef ICUSTOMER_H
#define ICUSTOMER_H
#include <memory>
#include <sstream>
#include <string>
#include "irental.h"

class ICustomer {
 public:
  virtual std::string name() const = 0;

  virtual void AddRental(IRentalPtr rental) = 0;
  virtual void RentalRecordsHeader(std::ostringstream& result) = 0;
  virtual void statement(std::ostringstream& result) = 0;
};
#endif  // ICUSTOMER_H
