#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <utility>
#include "board.h"
#include "dice.h"
#include "board.h"

class Player {
  vector<Board*> properties;
  int cash;
  int position;
  string name;
  vector<pair<string,int>> ownBlock;
  bool OSAPcollect;
  bool sentToDCTL;
  int DCTLtimes;
  int RUR_cup;
  Dice* dice;
public:
  Player(string name, int cash, int position, Dice* dice);
  int roll(Dice* dice);
  int getCashAmount();
  void giveCash(Player* p, int amount);
  void addProperties(Board* b);
  void sellProperties(Board* b);
  int getPosition();
  void addCash(int amount);
  int getStep();
  string getName();
  char getNameCapital();
  bool checkIfmonopoly();
  int getResidenceNum();
  string ifMonopoly();
  bool getOSAPcollect();
  void setOSAPcollect(bool boo);
  bool getsentToDCTL();
  void setsentToDCTL(bool boo);
  int getDCTLtimes();
  void setDCTLtimes(int times);
  int getRURCup();
  void setRURCup(int cup);
};

#endif
