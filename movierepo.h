#ifndef MOVIEREPO_H
#define MOVIEREPO_H
#include "imovierepo.h"

class MovieRepo : public IMovieRepo {
 public:
  MovieRepo();

  /**
   * @brief Add movie into the movie repo and return reference to it
   * @param line line to parse
   * @return reference to added movie
   */
  void Add(std::string line);
  IMovie& Find(int index) const;
  void PrintMovies(std::ostream& out) const;
  std::map<int, std::unique_ptr<IMovie> > movies_;
};

#endif  // MOVIEREPO_H
