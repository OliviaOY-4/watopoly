#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <utility>
#include "board.h"
#include "dice.h"
#include "board.h"

class Player {
  std::string name;
  char nameChar;
  int cash;
  int position;
  std::vector<Board*> property;
  std::vector<pair<std::string, int>> ownBlock;
  std::vector<std::string> monopoly;
  bool OSAPcollect;
  bool sentToDCTL;
  int DCTLtimes;
  int RUR_cup;
  Dice *dice; 
public:
  Player(std::string name, int cash, int position);
  ~Player();
  int roll();
  int getCashAmount();
  int getTotalWorth();
  void giveCash(Player* other, int amount);
  void addProperties(Board* b);
  void sellProperties(Board* b);
  int getPosition();
  void setPosition(int position);
  void addCash(int amount);
  std::string getName();
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
