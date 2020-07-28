#include "run.h"
#include <fstream>
#include <iomanip>
#include <map>
#include <sstream>
#include <vector>
#include "customer.h"
#include "movie.h"
#include "movierepo.h"
#include "rental.h"

IMovieRepoPtr FillMovieRepo() {
  IMovieRepoPtr movies = std::make_unique<MovieRepo>();
  std::ifstream movieStream{"movies.csv"};
  for (std::string line; std::getline(movieStream, line);) {
    movies->Add(line);
  }
  return std::move(movies);
}

std::unique_ptr<ICustomer> CreateCustomer(std::istream& in, std::ostream& out) {
  out << "Enter customer name: ";
  std::string customerName;
  getline(in, customerName);
  return std::make_unique<Customer>(customerName);
}

void ReadCustomerRentals(std::istream& in,
                         const IMovieRepo& movies,
                         ICustomer& customer_out) {
  while (true) {
    std::string input;
    std::getline(in, input);
    if (input.empty()) {
      break;
    }
    auto rental = Rental::createFromLine(input, movies);
    customer_out.AddRental(std::move(rental));
  }
}

void run(std::istream& in, std::ostream& out) {
  using namespace std::literals;
  auto movies = FillMovieRepo();
  movies->PrintMovies(out);
  auto customer = CreateCustomer(in, out);
  out << "Choose movie by number followed by rental days, just ENTER for "
         "bill:\n";
  std::ostringstream result;
  customer->RentalRecordsHeader(result);
  ReadCustomerRentals(in, *movies, *customer);
  customer->statement(result);
  out << result.str();
}
