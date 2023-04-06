#ifndef PROPERTY_H
#define PROPERTY_H

#include "board.h"
#include "player.h"

class Property: public Board {
  // Player* owner;
  std::shared_ptr<Player> owner;
  bool mortgage;
  std::unsigned_int purchasePrice;
  std::unsigned_int visitPrice;
public:
  Property(unsigned_int purchasePrice, unsigned_int visitPrice);
  ~Property();
  // Player* getOwner() const;
  // void setOwner(Player* owner);
  std::shared_ptr<Player> getOwner() const;
  void setOwner(std::shared_ptr<Player> owner);
  void changeMortgage(); 
  bool isMortgaged() const;
  virtual int getPrice() const = 0;
  // int getPurchasePrice() const;
  virtual void setVisitPrice() = 0;
  virtual int getVisitPrice(Player& visitor) const = 0;
};

#endif

