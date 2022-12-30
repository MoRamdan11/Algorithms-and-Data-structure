#include "Movie.h"
#include <iostream>

using std::cout;
using std::endl;


Movie::Movie(std::string name, std::string rating, int watched)
  : name{name}, rating{rating}, watched{watched} {
    cout << "Three args constructor" << endl;
}
Movie::Movie()
  : Movie{"None", "G", 0} {
    cout << "No args constructor" << endl;
}
Movie::~Movie() {
  std::cout << "Destructor called for Movie: " << name << std::endl;
}
Movie::Movie(const Movie &source) 
  : Movie{source.name, source.rating, source.watched} {
    cout << "Copy constructor called" << endl;
}
Movie::Movie(Movie &&source)
  : Movie{source.name, source.rating, source.watched} {
    cout << "Move constructor called" << endl;
}

void Movie::set_name(std::string name) {
  this->name = name;
}

string Movie::get_name() const {
  return name;
}

void Movie::set_rating() {
  this->rating = rating;
}

string Movie::get_rating() const {
  return rating;
}

void Movie::set_watched(int watched) {
  this->watched = watched;
}

int Movie::get_watched() const {
  return watched;
}

void Movie::increment_watched() {
  watched++;
}

void Movie::display_movie() const {
  cout << "Name: " << name << ", Rating: " << rating << ", Watched: " << watched << endl;
}