#ifndef NONPROPERTY_H
#define NONPROPERTY_H

#include "board.h"
#include <string>

class NonProperty: public Board {
public:
  // std::string getType() {
  //   return "NonProperty";
  // }
  virtual void action(player &p) = 0;
};

#endif
