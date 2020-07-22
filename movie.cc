#include "movie.h"
#include <memory>
#include <vector>

Movie::Movie(const std::string& movie_index,
             const std::string& movie_name,
             const std::string& movie_release_type)
    : index_(movie_index)
    , name_(movie_name)
    , release_type_(movie_release_type) {}

const std::string& Movie::name() const {
  return name_;
}

const std::string& Movie::release_type() const {
  return release_type_;
}

std::unique_ptr<Movie> Movie::createFromLine(const std::string& line) {
  std::vector<std::string> movie;
  for (size_t first = 0, last = 0; last < line.length(); first = last + 1) {
    last = line.find(';', first);
    movie.push_back(line.substr(first, last - first));
  }
  return std::make_unique<Movie>(movie[0], movie[1], movie[2]);
}

const std::string& Movie::index() const {
  return index_;
}
