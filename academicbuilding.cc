#include "academicbuilding.h"
using namespace std;


AcademicBuilding::AcademicBuilding(vector<unsigned int> tut, int improvementCost, string monopolyBlock): tutWithImprove{tut}, improvementCost{improvementCost}, improvementLevel{0}, monopolyBlock{monopolyBlock} {}

// AcademicBuilding::~AcademicBuilding() {
//   delete [] tutWithImprove;
// }

void AcademicBuilding::setVisitPrice(){
  visitPrice = tutWithImprove[improvementLevel];
}

int AcademicBuilding::getVisitPrice(Player& visitor) const {
  if (isMortgaged) return 0;
  if(owner.get()!=null){
    if (owner.get() != &visitor){
      return visitPrice;
    }
  }
}

int AcademicBuilding::getPrice() const {
  return purchasePrice + improvementCost * improvementLevel; 
}

// string AcademicBuilding::getType() {
//   // return "AcademicBuilding";
//   return type;
// }

string AcademicBuilding::getBlock() const{
  return monopolyBlock;
}

int AcademicBuilding::getImproveLevel() const {
  return improvementLevel;
}

int AcademicBuilding::getImproveCost() const {
  return improvementCost;
}

void AcademicBuilding::improve() {
  improvementLevel++;
}

void AcademicBuilding::degrade() {
  improvementLevel--;
}

