#include "academicbuilding.h"
using namespace std;


AcademicBuilding::AcademicBuilding(int *tut, int improvementLevel, int improvementCost, string monopolyBlock): improvementCost{improvementCost}, improvementLevel{improvementLevel}, monopolyBlock{monopolyBlock} {
  tutWithImprove[0] = tut[0];
  tutWithImprove[1] = tut[1];
  tutWithImprove[2] = tut[2];
  tutWithImprove[3] = tut[3];
  tutWithImprove[4] = tut[4];
  tutWithImprove[5] = tut[5];
}

AcademicBuilding::~AcademicBuilding() {
  delete [] tutWithImprove;
}

int AcademicBuilding::getVisitPrice(Player& visitor) {
  if (owner == &visitor || owner == nullptr) return 0;
  else return tutWithImprove[improvementLevel];
}

int AcademicBuilding::getPrice() {
  return price + improvementCost * improvementLevel;
}

string AcademicBuilding::getType() {
  return "AcademicBuilding";
}

string AcademicBuilding::getBlock() {
  return monopolyBlock;
}

void AcademicBuilding::improve() {
  improvementLevel++;
}

