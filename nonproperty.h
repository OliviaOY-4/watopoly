#ifndef NONPROPERTY_H
#define NONPROPERTY_H

#include "board.h"
#include <string>

class NonProperty: public Board {
public:
  string getType() {
    return "NonProperty";
  }
};

#endif
