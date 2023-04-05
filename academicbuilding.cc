#include "academicbuilding.h"
using namespace std;


AcademicBuilding::AcademicBuilding(vector<unsigned int> tut, int improvementCost, string monopolyBlock): tutWithImprove{tut}, improvementCost{improvementCost}, improvementLevel{0}, monopolyBlock{monopolyBlock} {}

// AcademicBuilding::~AcademicBuilding() {
//   delete [] tutWithImprove;
// }

void AcademicBuilding::setVisitPrice(){
  if (owner == &visitor || owner == nullptr) visitPrice= 0;
  else visitPrice = tutWithImprove[improvementLevel];
}

int AcademicBuilding::getVisitPrice(Player& visitor) {
  return visitPrice;
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

void AcademicBuilding::unimprove() {
  improvementLevel--;
}

