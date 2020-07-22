#ifndef IMOVIEREPO_H
#define IMOVIEREPO_H
#include <string>
#include "imovie.h"

class IMovieRepo {
public:
  virtual IMovie& Add(std::string line) = 0;
  virtual IMovie& Find(int index) const = 0;
};
#endif // IMOVIEREPO_H
