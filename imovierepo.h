#ifndef IMOVIEREPO_H
#define IMOVIEREPO_H
#include <memory>
#include <string>
#include "imovie.h"

class IMovieRepo {
 public:
  virtual void Add(std::string line) = 0;
  virtual IMovie& Find(int index) const = 0;
  virtual void PrintMovies(std::ostream& out) const = 0;
};
typedef std::unique_ptr<IMovieRepo> IMovieRepoPtr;
#endif  // IMOVIEREPO_H
