#ifndef _Illegal_Sufficient_FUND_
#define _Illegal_Sufficient_FUND_
#include <iostream>
class IllegalSufficientFund : std::exception {
public:
  IllegalSufficientFund()=default;
  virtual ~IllegalSufficientFund()=default;
  virtual const char* what() const noexcept override {
    return "EXCEPTION: Illegal Sufficient FUND";
  }
};

#endif