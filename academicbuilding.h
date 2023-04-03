#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "property.h"
#include "player.h"
#include <string>

class AcademicBuilding: public Property {
  int tutWithImprove[6];
  int improvementLevel;
  int improvementCost;
  string monopolyBlock;
public:
  AcademicBuilding(int* tut, int improvementLevel, int improvementCost, string monopolyBlock);
  ~AcademicBuilding();
  int getVisitPrice(Player& visitor) const;
  int getPrice() const;
  string getType() const;
  string getBlock() const;
  void improve();
};

#endif
