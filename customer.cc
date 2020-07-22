#include "customer.h"

Customer::Customer(const std::string& name) : name_(name) {}


std::string Customer::name() const {
  return name_;
}

void Customer::AddRental(const Rental& rental) {
  rentals_.push_back(rental);
}

void Customer::statement(std::ostringstream& result) {
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  for (auto rental : rentals_) {
    Movie movie = rental.movie();
    double thisAmount = 0;
    // determine amounts for rental
    if (movie.release_type() == "REGULAR") {
      thisAmount += 2;
      if (rental.days_rented() > 2)
        thisAmount += (rental.days_rented() - 2) * 1.5;
    } else if (movie.release_type() == "NEW_RELEASE") {
      thisAmount += rental.days_rented() * 3;
    } else if (movie.release_type() == "CHILDRENS") {
      thisAmount += 1.5;
      if (rental.days_rented() > 3)
        thisAmount += (rental.days_rented() - 3) * 1.5;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if (movie.release_type() == "NEW_RELEASE" && rental.days_rented() > 1) {
      frequentRenterPoints++;
    }
    // show figures for this rental
    result << "\t" << movie.name() + "\t" << thisAmount << "\n";
    totalAmount += thisAmount;
  }

  // add footer lines
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points\n";
}
