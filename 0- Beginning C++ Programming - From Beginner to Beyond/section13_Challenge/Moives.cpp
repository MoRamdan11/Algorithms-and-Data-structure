#include "Movies.h"
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

//Movies::Movies();
bool Movies::add_movie(string name, string rating, int watched) {
  bool movie_found{false}, movie_added{false};
  for(const auto &movie : movies) {
    if(movie.get_name() == name) {
      cout << "Movie " << name << " already exists" << endl;
      movie_found = true;
      movie_added = false;
    }
  }
  if(!movie_found) {
    Movie movie{name, rating, watched};
    movies.push_back(movie);
    movie_added = true;
  }
  return movie_added;
}

bool Movies::increment_watched(string name) {
  bool movie_incremented{false};
  for(auto &movie : movies) {
    if(movie.get_name() == name) {
      movie.increment_watched();
      movie_incremented = true;
      break;
    }
  }
  return movie_incremented;
}

void Movies::display() const{
  cout << "====================Movies info=====================" << endl;
  for(const auto &movie : movies)
    movie.display_movie();
  cout << "=====================================================" << endl;
}