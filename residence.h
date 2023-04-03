#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "property.h"

class Residence: public Property {
public:
  int getPrice() const;
  std::string getType() const;
  int getVisitPrice(Player& p) const;
};

#endif

