#ifndef IMOVIE_H
#define IMOVIE_H

#include <map>
#include <memory>
#include <string>
#include <unordered_map>

enum class ReleaseType { REGULAR, NEW_RELEASE, CHILDRENS };

class IMovie {
 public:
  virtual const std::string& name() const = 0;

  virtual double GetTotalAmount(const int days_rented) const = 0;
  virtual int GetFrequentRenterPoints(const int days_rented) const = 0;

  virtual const int index() const = 0;
};

#endif  // IMOVIE_H
