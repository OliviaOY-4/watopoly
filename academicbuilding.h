#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "property.h"
#include "player.h"
#include <string>

class AcademicBuilding: public Property {
  int tutWithImprove[5];
  int improvementLevel;
  int improvementCost;
  string monopolyBlock;
public:
  AcademicBuilding(string monopolyBlock, int improvementLevel, int improvementCost, int, string);
  int getTuition();
  int getPrice();
  void changeMortgage();
  void getVisitPrice(Player&);
  void changeVisitPrice();
};

#endif
