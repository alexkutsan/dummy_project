#include "rental.h"
#include <vector>
#include "movierepo.h"

Rental::Rental(int days_rented, const IMovie& movie)
    : days_rented_(days_rented), movie_(movie) {}

IRentalPtr Rental::createFromLine(const std::string& line,
                              const IMovieRepo& movies) {
  std::vector<std::string> rental;
  for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
    last = line.find(' ', first);
    rental.push_back(line.substr(first, last - first));
  }
  int daysRented = std::stoi(rental[1]);
  auto& movie = movies.Find(std::stoi(rental[0]));
  return std::make_unique<Rental>(daysRented, movie);
}

int Rental::days_rented() const {
  return days_rented_;
}

const IMovie& Rental::movie() const {
    return movie_;
}

double Rental::GetTotalAmount() const {
    double thisAmount = 0;
    // determine amounts for rental
    if (movie_.release_type() == "REGULAR") {
      thisAmount += 2;
      if (days_rented() > 2)
        thisAmount += (days_rented() - 2) * 1.5;
    } else if (movie_.release_type() == "NEW_RELEASE") {
      thisAmount += days_rented() * 3;
    } else if (movie_.release_type() == "CHILDRENS") {
      thisAmount += 1.5;
      if (days_rented() > 3)
        thisAmount += (days_rented() - 3) * 1.5;
    }
    return thisAmount;
}

double Rental::GetFrequentRenterPoints() const {
    // add bonus for a two day new release rental
    if (movie_.release_type() == "NEW_RELEASE" && days_rented() > 1) {
      return 2;
    }
    return 1;
}
