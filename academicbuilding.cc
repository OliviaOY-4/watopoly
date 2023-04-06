#include "academicbuilding.h"
using namespace std;


AcademicBuilding::AcademicBuilding(vector<unsigned int> tut, int improvementCost, string monopolyBlock): tutWithImprove{tut}, improvementCost{improvementCost}, improvementLevel{0}, monopolyBlock{monopolyBlock} {}

// AcademicBuilding::~AcademicBuilding() {
//   delete [] tutWithImprove;
// }

void AcademicBuilding::setVisitPrice(){
  visitPrice = tutWithImprove[improvementLevel];
}

int AcademicBuilding::getVisitPrice(Player& visitor) {
  if (isMortgaged) return 0;
  if (owner == &visitor || owner == nullptr) return 0;
  else return tutWithImprove[improvementLevel];
}

int AcademicBuilding::getPrice() {
  return price + improvementCost * improvementLevel; 
}

// string AcademicBuilding::getType() {
//   // return "AcademicBuilding";
//   return type;
// }

string AcademicBuilding::getBlock() {
  return monopolyBlock;
}

int getImproveLevel() {
  return improvementLevel;
}

int getImproveCost() {
  return improvementCost;
}

void AcademicBuilding::improve() {
  improvementLevel++;
}

void AcademicBuilding::degrade() {
  improvementLevel--;
}

