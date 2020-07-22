#ifndef MOVIE_H
#define MOVIE_H
#include "imovie.h"

class Movie : public IMovie {
public:
 Movie(const int movie_index,
       const std::string& movie_name,
       const std::string& movie_release_type);

 const std::string& name() const override;

 const std::string& release_type() const override;

 const int index() const override;

private:
 const int index_;
 const std::string name_;
 const std::string release_type_;
};
#endif // MOVIE_H
