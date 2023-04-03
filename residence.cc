#include "residence.h"
using namespace std;

int roll() {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % 6 + 1;
  return randnum;
}

int Residence::getPrice() {
  return 200;
}

string Residence::getType() {
  return "Residence";
}

int Residence::getVisitPrice(Player& visitor) {
  if (owner == &visitor || owner == nullptr) return 0;
  int price1 = roll();
  int price2 = roll();
  int price = price1 + price2;
  int count = 0;
  for (int i = 0; i < owner.property().size(); i++) {
    if (owner.property()[i]->getType() == "Residence") count++;
  } if (count == 1) visitPrice = 25;
  else if (count == 2) visitPrice = 50;
  else if (count == 3) visitPrice = 100;
  else if (count == 4) visitPrice = 200;
  return visitPrice;
}

