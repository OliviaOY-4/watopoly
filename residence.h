#ifndef RESIDENCE_H
#define RESIDENCE_H

#include "property.h"

class Residence: public Property {
public:
  int getPrice();
  void changeMortgage();
  int getVisitPrice(Player& p);
  void changeVisitPrice();

};

#endif

