#ifndef _IPRINTABLE_H_
#define _IPRINTABLE_H_
#include <iostream>

// Interface
class I_Printable {
friend std::ostream &operator <<(std::ostream &os, const I_Printable &obj);
public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Printable() = default;
};

#endif