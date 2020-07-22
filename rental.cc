#include "rental.h"
#include <vector>

Rental::Rental(int days_rented, Movie movie)
    : days_rented_(days_rented), movie_(movie) {}

Rental Rental::createFromLine(const std::string& line,
                              const std::map<int, Movie>& movies) {
  std::vector<std::string> rental;
  for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
    last = line.find(' ', first);
    rental.push_back(line.substr(first, last - first));
  }
  int daysRented = std::stoi(rental[1]);
  Movie movie = movies.at(std::stoi(rental[0]));
  return Rental(daysRented, movie);
}

int Rental::days_rented() const {
  return days_rented_;
}

Movie Rental::movie() const {
  return movie_;
}
