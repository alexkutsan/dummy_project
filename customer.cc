#include "customer.h"

Customer::Customer(const std::string& name) : name_(name) {}

std::string Customer::name() const {
  return name_;
}

void Customer::AddRental(const Rental& rental) {
  rentals_.push_back(rental);
}

int Customer::GetTotatFrequentRenterPoints() {
    int frequentRenterPoints = 0;
    for (auto rental : rentals_) {
      frequentRenterPoints += rental.GetFrequentRenterPoints();
    }
    return frequentRenterPoints;
}

double Customer::GetTotalAmount() {
    double totalAmount = 0;
    for (auto rental : rentals_) {
      totalAmount += rental.GetTotalAmount();
    }

    return totalAmount;
}

void Customer::AddFooter(std::ostringstream& result) {
    result << "You owed " <<  GetTotalAmount() << "\n";
    result << "You earned " << GetTotatFrequentRenterPoints()
           << " frequent renter points\n";
}

void Customer::statement(std::ostringstream& result) {

  for (auto rental : rentals_) {
    auto& movie = rental.movie();
    result << "\t" << movie.name() + "\t" << rental.GetTotalAmount() << "\n";
  }

  AddFooter(result);
}
