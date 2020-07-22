#include "movie.h"
#include <memory>
#include <vector>

Movie::Movie(const int movie_index,
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

const int Movie::index() const {
  return index_;
}
