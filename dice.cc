#include "dice.h"
#include <iostream>
#include <ctime>
#include <cstdlib>


int Dice::rollDice() {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % 6 + 1;
  return randnum;
}
