#include "run.h"
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>
class Movie {
 public:
  Movie(const std::string& movie_index,
        const std::string& movie_name,
        const std::string& movie_release_type)
      : index_(movie_index)
      , name_(movie_name)
      , release_type_(movie_release_type) {}

  const std::string& name() const;

  const std::string& release_type() const;

  static Movie createFromLine(const std::string& line) {
    std::vector<std::string> movie;
    for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
      last = line.find(';', first);
      movie.push_back(line.substr(first, last - first));
    }
    return Movie(movie[0], movie[1], movie[2]);
  }

  const std::string& index() const;

 private:
  const std::string index_;
  const std::string name_;
  const std::string release_type_;
};

class Rental {
 public:
  Rental(int days_rented, Movie movie)
      : days_rented_(days_rented), movie_(movie) {}

  int days_rented() const;

  Movie movie() const;

 private:
  int days_rented_;
  Movie movie_;
};

class Customer {
 public:
  Customer(const std::string& name) : name_(name) {}

  std::string name() const;

  void AddRental(const Rental& rental);

 private:
  std::string name_;
  std::vector<Rental> rentals_;
};

void run(std::istream& in, std::ostream& out) {
  using namespace std::literals;
  // read movies from file
  std::ifstream movieStream{"movies.csv"};
  std::map<int, Movie> movies{};
  for (std::string line; std::getline(movieStream, line);) {
    Movie movie = Movie::createFromLine(line);
    movies.insert(std::make_pair(std::stoi(movie.index()), movie));
    out << movie.index() << ": " << movie.name() << "\n";
  }
  out << "Enter customer name: ";
  std::string customerName;
  getline(in, customerName);

  out << "Choose movie by number followed by rental days, just ENTER for "
         "bill:\n";
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  std::ostringstream result;
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + customerName + "\n";
  while (true) {
    std::string input;
    std::getline(in, input);
    if (input.empty()) {
      break;
    }
    std::vector<std::string> rental;
    for (size_t first = 0, last = 0; last < input.length(); first = last + 1) {
      last = input.find(' ', first);
      rental.push_back(input.substr(first, last - first));
    }
    Movie movie = movies.at(std::stoi(rental[0]));
    double thisAmount = 0;
    int daysRented = std::stoi(rental[1]);
    // determine amounts for rental
    if (movie.release_type() == "REGULAR") {
      thisAmount += 2;
      if (daysRented > 2)
        thisAmount += (daysRented - 2) * 1.5;
    } else if (movie.release_type() == "NEW_RELEASE") {
      thisAmount += daysRented * 3;
    } else if (movie.release_type() == "CHILDRENS") {
      thisAmount += 1.5;
      if (daysRented > 3)
        thisAmount += (daysRented - 3) * 1.5;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if (movie.release_type() == "NEW_RELEASE" && daysRented > 1) {
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

  out << result.str();
}

const std::string& Movie::name() const {
  return name_;
}

const std::string& Movie::release_type() const {
  return release_type_;
}

const std::string& Movie::index() const {
  return index_;
}

int Rental::days_rented() const {
  return days_rented_;
}

Movie Rental::movie() const {
  return movie_;
}

std::string Customer::name() const {
  return name_;
}

void Customer::AddRental(const Rental& rental) {
  rentals_.push_back(rental);
}
