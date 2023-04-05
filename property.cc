#include "property.h"
using namespace std;

// Property::Property(unsigned_int purchasePrice, unsigned_int visitPrice): owner{nullptr}, mortgage{false}, purchasePrice{purchasePrice}, visitPrice{visitPrice} {}
Property::Property(unsigned_int purchasePrice, unsigned_int visitPrice): owner{nullptr}, mortgage{false}, purchasePrice{purchasePrice}, visitPrice{visitPrice} {}

// Property::~Property() {
//   if (!owner == nullptr) owner=nullptr;//???
// }

Property::~Property() {} //don't need delete

// void Property::setOwner(Player *owner) {
//   this->owner = owner;
// }
void Property::setOwner(shared_ptr<Player> owner) {
  this->owner = owner;
}

// Player *Property::getOwner() {
//   return owner;
// }

shared_ptr<Player> Property::getOwner() {
  return owner;
}

void Property::changeMortgage() {
  mortgage = !mortgage;
}

bool Property::isMortgaged() {
  return mortgage;
}

int Property::getPurchasePrice(){
  return purchasePrice;
}
