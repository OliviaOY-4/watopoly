#ifndef PROPERTY_H
#define PROPERTY_H

#include <memory>
#include "board.h"
#include "player.h"

class Property: public Board {
  // Player* owner;
protected:
  std::shared_ptr<Player> owner;
  bool mortgage;
  unsigned int purchasePrice;
  unsigned int visitPrice;
public:
  Property(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice);
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

