#include "movierepo.h"
#include <vector>
#include "movie.h"
MovieRepo::MovieRepo() {}

IMovie& MovieRepo::Add(std::string line) {
  std::vector<std::string> movie_row;
  for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
    last = line.find(';', first);
    movie_row.push_back(line.substr(first, last - first));
  }
  int movie_index = std::stoi(movie_row[0]);
  auto movie = std::make_unique<Movie>(movie_index, movie_row[1], movie_row[2]);
  movies_[movie_index] = std::move(movie);
  return *movies_.at(movie_index);
}

IMovie& MovieRepo::Find(int index) const {
  return *movies_.at(index);
}
