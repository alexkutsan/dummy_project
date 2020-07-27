#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include "icustomer.h"
class Customer :ICustomer {
 public:
  Customer(const std::string& name);

  std::string name() const;

  void AddRental(const Rental& rental);

  void statement(std::ostringstream& result);

  void AddFooter(std::ostringstream& result);
  
private:
  std::string name_;
  std::vector<Rental> rentals_;
  int GetTotatFrequentRenterPoints();
  double GetTotalAmount();
};
#endif // CUSTOMER_H
