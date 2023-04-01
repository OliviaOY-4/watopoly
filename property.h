#ifndef PROPERTY_H
#define PROPERTY_H

#include "board.h"
#include "player.h"

class Property: public Board {
  Player* owner;
  bool mortgage;
  unsigned_int purchasePrice;
  unsigned_int visitPrice;
public:
  Property();
  Property(Player* owner, bool mortgage, unsigned_int purchasePrice, unsigned_int visitPrice);
  ~Property();
  Player* getOwner();
  void setOwner(Player* owner);
  string getType();
  int getPrice();
  void changeMortgage();
  int getVisitPrice();
  void changeVisitPrice(Player& owner);
};

#endif

