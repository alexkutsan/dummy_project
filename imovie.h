#ifndef IMOVIE_H
#define IMOVIE_H

#include <string>

class IMovie {
public:
  virtual const std::string& name() const = 0;

  virtual const std::string& release_type() const = 0;

  virtual const std::string& index() const = 0;
};
#endif // IMOVIE_H
