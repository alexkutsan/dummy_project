#include "movierepo.h"
#include "movieprice.h"

#include <sstream>
#include <vector>
#include "movie.h"
MovieRepo::MovieRepo() {}

void MovieRepo::Add(std::string line) {
  std::vector<std::string> movie_row;
  for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
    last = line.find(';', first);
    movie_row.push_back(line.substr(first, last - first));
  }
  int movie_index = std::stoi(movie_row[0]);
  auto release_type = ReleaseTypeFromString(movie_row[2]);
  auto price_calculator = MoviePrice::PriceCalculatorFactory(release_type);
  auto frequent_points_calculator =
      MoviePrice::FrequentPointsCalculatorFactory(release_type);
  auto movie = std::make_unique<Movie>(
      movie_index, movie_row[1], price_calculator, frequent_points_calculator);
  movies_[movie_index] = std::move(movie);
}

IMovie& MovieRepo::Find(int index) const {
  return *movies_.at(index);
}

void MovieRepo::PrintMovies(std::ostream& out) const {
  for (const auto& movie_pair : movies_) {
    const auto& movie = movie_pair.second;
    out << movie->index() << ": " << movie->name() << "\n";
  }
}
