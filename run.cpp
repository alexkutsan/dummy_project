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

  static Rental createFromLine(const std::string& line,
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

 private:
  int days_rented_;
  Movie movie_;
};

class Customer {
 public:
  Customer(const std::string& name) : name_(name) {}

  std::string name() const;

  void AddRental(const Rental& rental);

  void statement(std::ostringstream& result) {
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

  Customer customer(customerName);

  out << "Choose movie by number followed by rental days, just ENTER for "
         "bill:\n";
  std::ostringstream result;
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + customer.name() + "\n";

  while (true) {
    std::string input;
    std::getline(in, input);
    if (input.empty()) {
      break;
    }
    auto rental = Rental::createFromLine(input, movies);
    customer.AddRental(rental);
  }

  customer.statement(result);

  out << result.str();
}

void run_original(std::istream& in, std::ostream& out) {
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

  Customer customer(customerName);

  out << "Choose movie by number followed by rental days, just ENTER for "
         "bill:\n";
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  std::ostringstream result;
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + customer.name() + "\n";
  while (true) {
    std::string input;
    std::getline(in, input);
    if (input.empty()) {
      break;
    }
    auto rental = Rental::createFromLine(input, movies);

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
