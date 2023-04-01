#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "property.h"
#include "player.h"

class AcademicBuilding: public Property {
  int tutWithImprove[5];
  int improvementLevel;
  int improvementCost;
  string monopolyBlock;
public:
  AcademicBuilding(string, int, int, int, string);
  int getTuition();
  int getPrice();
  void changeMortgage();
  void getVisitPrice(Player&);
  void changeVisitPrice();
};

#endif
