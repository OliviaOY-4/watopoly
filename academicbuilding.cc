#include "academicbuilding.h"
using namespace std;


AcademicBuilding::AcademicBuilding(int position, string name, unsigned int purchasePrice, unsigned int visitPrice, vector<unsigned int> tut, int improvementCost, string monopolyBlock): Property{position, name, purchasePrice, visitPrice}, tutWithImprove{tut}, improvementLevel{0}, improvementCost{improvementCost}, monopolyBlock{monopolyBlock} {}

// AcademicBuilding::~AcademicBuilding() {
//   delete [] tutWithImprove;
// }

void setVisitPrice() {
  return;
}

int AcademicBuilding::getVisitPrice(Player& visitor) const {
  if (isMortgaged()) return 0;
  if (owner.get() == &visitor || owner == nullptr) return 0;
  else return tutWithImprove[improvementLevel];
}

int AcademicBuilding::getPrice() const {
  return purchasePrice + improvementCost * improvementLevel; 
}

// string AcademicBuilding::getType() {
//   // return "AcademicBuilding";
//   return type;
// }

string AcademicBuilding::getBlock() const {
  return monopolyBlock;
}

int AcademicBuilding::getImproveLevel() const {
  return improvementLevel;
}

int AcademicBuilding::getImproveCost() const{
  return improvementCost;
}

void AcademicBuilding::improve() {
  improvementLevel++;
}

void AcademicBuilding::degrade() {
  improvementLevel--;
}

