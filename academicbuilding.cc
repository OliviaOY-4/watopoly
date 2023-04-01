#include "academicbuilding.h"

class AcademicBuilding: public Property {
  int tutWithImprove[5];
  int improvementLevel;
  int improvementCost;
  string monopolyBlock;
};


  AcademicBuilding(string, int, int, int, string);
  int getTuition();
  int getPrice();
  void changeMortgage();
  void getVisitPrice(Player&);
  void changeVisitPrice();
};