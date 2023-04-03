#include "property.h"

Property::Property(unsigned_int purchasePrice, unsigned_int visitPrice): owner{nullptr}, mortgage{false}, purchasePrice{purchasePrice}, visitPrice{visitPrice} {}

Property::~Property() {
  if (!owner == nullptr) delete owner;
}

void Property::setOwner(Player *owner) {
  this->owner = owner;
}

Player *Property::getOwner() {
  return owner;
}

void Property::changeMortgage() {
  mortgage = !mortgage;
}

bool Property::isMortgaged() {
  return mortgage;
}
