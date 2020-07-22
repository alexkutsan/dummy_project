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

void run(std::istream& in, std::ostream& out) {
  using namespace std::literals;
  // read movies from file
  std::ifstream movieStream{"movies.csv"};
  MovieRepo movies;
  for (std::string line; std::getline(movieStream, line);) {
    auto& movie = movies.Add(line);
    //    auto movie = Movie::createFromLine(line);
    out << movie.index() << ": " << movie.name() << "\n";
    //    movies.insert(std::make_pair(std::stoi(movie->index()),
    //    std::move(movie)));
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
