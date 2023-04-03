#ifndef PROPERTY_H
#define PROPERTY_H

#include "board.h"
#include "player.h"

class Property: public Board {
  Player* owner;
  bool mortgage;
  std::unsigned_int purchasePrice;
  std::unsigned_int visitPrice;
public:
  Property(unsigned_int purchasePrice, unsigned_int visitPrice);
  ~Property();
  Player* getOwner() const;
  void setOwner(Player* owner);
  void changeMortgage();
  bool isMortgaged() const;
  int getPrice() = 0;
  int getVisitPrice() = 0;
};

#endif

