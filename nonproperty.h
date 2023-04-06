#ifndef NONPROPERTY_H
#define NONPROPERTY_H

#include "board.h"
#include <string>
#include "player.h"

class NonProperty: public Board {
public:
  // std::string getType() {
  //   return "NonProperty";
  // }
  NonProperty(int position, std::string name): Board(position, name) {};
  virtual ~NonProperty() = 0;
  virtual void action(Player &p) = 0;
};

#endif
