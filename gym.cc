#include "gym.h"
using namespace std;

int roll() {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % 6 + 1;
  return randnum;
}

int Gym::getPrice() {
  //return 150;
  return purchasePrice;
}

// string Gym::getType() {
//   return "Gym";
// }

void Gym::setVisitPrice(){
  int price1 = roll();
  int price2 = roll();
  int price = price1 + price2;
  int count = 0;
  for (int i = 0; i < owner.property.size(); i++) {
    if (owner.property[i]->getType() == "Gym") count++;
  } 
  if (count == 1) visitPrice = price * 4;
  else if (count == 2) visitPrice = price * 10;
}

int Gym::getVisitPrice(Player& visitor) {
  return visitPrice;
}


