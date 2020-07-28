#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "icustomer.h"

class Customer : public ICustomer {
 public:
  Customer(const std::string& name);

  std::string name() const;

  void AddRental(IRentalPtr rental);

  void statement(std::ostringstream& result);

  void AddFooter(std::ostringstream& result);
  void RentalRecordsHeader(std::ostringstream& result) override;

 private:
  std::string name_;
  std::vector<std::unique_ptr<IRental> > rentals_;
  int GetTotatFrequentRenterPoints();
  double GetTotalAmount();
};
#endif  // CUSTOMER_H
