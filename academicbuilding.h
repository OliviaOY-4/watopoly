#ifndef ACADEMICBUILDING_H
#define ACADEMICBUILDING_H

#include "property.h"
#include "player.h"
#include <string>

class AcademicBuilding: public Property {
  int tutWithImprove[6];
  int improvementLevel;
  int improvementCost;
  std::string monopolyBlock;
public:
  AcademicBuilding(int* tut, int improvementLevel, int improvementCost, std::string monopolyBlock);
  ~AcademicBuilding();
  int getVisitPrice(Player& visitor) const;
  int getPrice() const;
  std::string getType() const;
  std::string getBlock() const;
  int getImproveLevel() const;
  int getImproveCost() const;
  void improve();
};

#endif
