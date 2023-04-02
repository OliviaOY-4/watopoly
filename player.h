#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <utility>
#include "board.h"
#include "dice.h"
#include "board.h"

class Player {
  string name;
  char nameChar;
  int cash;
  int position;
  vector<Board*> property;
  vector<pair<string, int>> ownBlock;
  vector<string> monopoly;
  bool OSAPcollect;
  bool sentToDCTL;
  int DCTLtimes;
  int RUR_cup;
  Dice *dice; 
public:
  Player(string name, int cash, int position);
  ~Player();
  int roll();
  int getCashAmount();
  int getTotalWorth();
  void giveCash(Player* other, int amount);
  void addProperties(Board* b);
  void sellProperties(Board* b);
  int getPosition();
  void addCash(int amount);
  string getName();
  char getNameChar();
  void ifMonopoly(Board type);
  int getResidenceNum();
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
