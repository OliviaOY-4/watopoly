#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "property.h"

class Residence: public Property {
public:
  Residence(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice);
  ~Residence();
  int getPrice() const;
  // std::string getType() const;
  int getVisitPrice(Player& visitor) const;
  void setVisitPrice();
};

#endif

