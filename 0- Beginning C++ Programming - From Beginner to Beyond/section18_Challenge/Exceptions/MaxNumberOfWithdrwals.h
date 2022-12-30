#ifndef MAX_NUMBER_OF_WITHDRWALS_H_
#define MAX_NUMBER_OF_WITHDRWALS_H_
#include <iostream>

class MaxNumberOfWithdrwals : std::exception {
public:
  MaxNumberOfWithdrwals()=default;
  virtual ~MaxNumberOfWithdrwals()=default;
  virtual const char* what() const noexcept override {
    return "EXCEPTION: Reaching max number of withdrwals";
  }
};

#endif