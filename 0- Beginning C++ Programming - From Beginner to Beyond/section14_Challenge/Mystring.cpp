#include "Mystring.h"
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <ostream>
using namespace std;

// Overloaded constructor
Mystring::Mystring(const char *s) 
  : str{nullptr} {
    if(s == nullptr) {
      str = new char[1];
      *str = '\0';
    } else {
      str = new char[strlen(s) + 1];
      strcpy(this->str, s);
    }
    cout << "Three args constructor" << endl;
}
// No-args constructor
Mystring::Mystring() 
  : Mystring{nullptr} { 
    cout << "No args constructor" << endl;
}
// Copy constructor             
Mystring::Mystring(const Mystring &source) {
  this->str = new char[strlen(source.str) + 1];
  strcpy(this->str, source.str);
  cout << "Copy constructor called" << endl;
}
// Move constructor
Mystring::Mystring( Mystring &&source) {
  this->str = source.str;
  source.str = nullptr;
  cout << "Move constructor called" << endl;
}
// Destructor
Mystring::~Mystring() {
  delete [] str;
  cout << "Destructor called" << endl;
}
// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
  if(this == &rhs)
    return *this;
  delete [] this->str;
  this->str = new char[strlen(rhs.str) + 1];
  strcpy(this->str, rhs.str);
  return *this;
}
// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
  if(this == &rhs)
    return *this;
  delete [] this->str;
  this->str = rhs.str;
  rhs.str = nullptr;
  return *this;
}       

Mystring Mystring::operator-() const {
  char *buff = new char[strlen(this->str) + 1];
  strcpy(buff, this->str);
  for(size_t i{}; i < strlen(buff); i++)
    buff[i] = tolower(buff[i]);
  Mystring obj{buff};
  delete [] buff;
  return obj;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
  int buff_size = strlen(this->str) + strlen(rhs.str) + 1;
  char *buff = new char[buff_size];
  strcpy(buff, this->str);
  strcat(buff, rhs.str);
  Mystring obj{buff};
  delete [] buff;
  return obj;
}

bool Mystring::operator==(const Mystring &rhs) const {
  return (strcmp(this->str, rhs.str) == 0);
}             // equals
bool Mystring::operator!=(const Mystring &rhs) const {
  return (strcmp(this->str, rhs.str) != 0);
}              //not equals
bool Mystring::operator<(const Mystring &rhs) const {
  return (strcmp(this->str, rhs.str) < 0);
}              //less than
bool Mystring::operator>(const Mystring &rhs) const {
  return (strcmp(this->str, rhs.str) > 0);
}              //greater than

Mystring &Mystring::operator+=(const Mystring &rhs) {
  *this = *this + rhs;
  return *this;
}

Mystring Mystring::operator*(int n) const {
  size_t buff_size {strlen(this->str) * n + 1};
  char *buff = new char[buff_size];
  strcpy(buff, "");
  for(int i{}; i < n; i++)
    strcat(buff, this->str);
  Mystring obj{buff};
  delete [] buff;
  return obj;
}                            
Mystring &Mystring::operator*=(int n) {
  *this = *this * n;
  return *this;
}

Mystring &Mystring::operator++() {
  for(size_t i{}; i < strlen(this->str); i++)
    this->str[i] = toupper(this->str[i]);
  return *this;
}
Mystring Mystring::operator++(int) {
  Mystring temp{this->str};
  ++(*this);
  return temp;
} 


void Mystring::display() const {
  cout << this->str << " : " << strlen(this->str) << endl;
}
int Mystring::get_length() const {
  return strlen(this->str);
}
const char *Mystring::get_str() const {
  return this->str;
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
  os << rhs.str;
  return os;
}

std::istream &operator>>(std::istream &in, Mystring &rhs) {
  char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}