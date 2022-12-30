#ifndef _ILLEGAL_BALANCE_EXCEPTION_
#define _ILLEGAL_BALANCE_EXCEPTION_
#include <iostream>

class IllegalBalanceException : public std::exception {
public:
  IllegalBalanceException() = default;
  ~IllegalBalanceException() = default;
  virtual const char* what() const noexcept override {
    return "EXCEPTION: Illegal Balance";
  }
};


#endif