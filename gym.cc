#include "gym.h"
using namespace std;

Gym::Gym(int position, std::string name, unsigned int purchasePrice, unsigned int visitPrice): Property{position, name, purchasePrice, visitPrice} {}

Gym::~Gym() {}


int roll() {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % 6 + 1;
  return randnum;
}

int Gym::getPrice() const {
  //return 150;
  return purchasePrice;
}

// string Gym::getType() {
//   return "Gym";
// }

int Gym::getVisitPrice(Player& visitor) {
  if (isMortgaged()) return 0;
  if (owner.get() == &visitor || owner == nullptr) return 0;
  else {
    setVisitPrice();
    return visitPrice;
  }
}

void Gym::setVisitPrice(){
  int price1 = roll();
  int price2 = roll();
  int price = price1 + price2;
  int count = owner->getGymNum();
  if (count == 1) visitPrice = price * 4;
  else if (count == 2) visitPrice = price * 10;
}



