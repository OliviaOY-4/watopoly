#ifndef GYM_H
#define GYM_H

#include "property.h"

class Gym: public Property {
public:
  int getPrice() const;
  std::string getType() const;
  int getVisitPrice(Player& visitor) const;
};

#endif

