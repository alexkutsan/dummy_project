#ifndef IMOVIE_H
#define IMOVIE_H

#include <string>
#include <map>
#include <memory>

class IMovie {
public:
  virtual const std::string& name() const = 0;

  virtual const std::string& release_type() const = 0;

  virtual const std::string& index() const = 0;
};

typedef std::map<int, std::unique_ptr<IMovie>> MovieRepo;
#endif // IMOVIE_H
