#include "rental.h"
#include <vector>
#include "movierepo.h"

Rental::Rental(int days_rented, const IMovie& movie)
    : days_rented_(days_rented), movie_(movie) {}

Rental Rental::createFromLine(const std::string& line,
                              const IMovieRepo& movies) {
  std::vector<std::string> rental;
  for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
    last = line.find(' ', first);
    rental.push_back(line.substr(first, last - first));
  }
  int daysRented = std::stoi(rental[1]);
  auto& movie = movies.Find(std::stoi(rental[0]));
  return Rental(daysRented, movie);
}

int Rental::days_rented() const {
  return days_rented_;
}

const IMovie& Rental::movie() const {
  return movie_;
}
