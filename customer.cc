#include "customer.h"
#include <iomanip>

Customer::Customer(const std::string& name) : name_(name) {}

std::string Customer::name() const {
  return name_;
}

void Customer::AddRental(IRentalPtr rental) {
  rentals_.push_back(std::move(rental));
}

int Customer::GetTotatFrequentRenterPoints() {
  int frequentRenterPoints = 0;
  for (auto& rental : rentals_) {
    frequentRenterPoints += rental->GetFrequentRenterPoints();
  }
  return frequentRenterPoints;
}

double Customer::GetTotalAmount() {
  double totalAmount = 0;
  for (auto& rental : rentals_) {
    totalAmount += rental->GetTotalAmount();
  }

  return totalAmount;
}

void Customer::AddFooter(std::ostringstream& result) {
  result << "You owed " << GetTotalAmount() << "\n";
  result << "You earned " << GetTotatFrequentRenterPoints()
         << " frequent renter points\n";
}

void Customer::RentalRecordsHeader(std::ostringstream& result) {
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + name() + "\n";
}

void Customer::statement(std::ostringstream& result) {
  for (auto& rental : rentals_) {
    auto& movie = rental->movie();
    result << "\t" << movie.name() + "\t" << rental->GetTotalAmount() << "\n";
  }

  AddFooter(result);
}
