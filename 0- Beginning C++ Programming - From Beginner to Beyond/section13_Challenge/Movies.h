#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <vector>

using std::string;
using std::vector;

class Movies{
private:
  vector<Movie> movies;
public:
  //Movies();
  bool add_movie(string name, string rating, int watched);
  bool increment_watched(string name);
  void display() const;
};

#endif