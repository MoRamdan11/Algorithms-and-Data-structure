#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

using std::string;

class Movie {
private:
  string name;
  string rating;
  int watched;
public:
  Movie(string name, string rating, int watched);
  Movie();
  ~Movie();
  Movie(const Movie &source);
  Movie(Movie &&source);
  void set_name(string name);
  string get_name() const;
  void set_rating();
  string get_rating() const;
  void set_watched(int watched);
  int get_watched() const;
  void increment_watched();
  void display_movie() const;
};

#endif