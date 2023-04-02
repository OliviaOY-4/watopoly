#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include "board.h"
#include "player.h"
#include "dice.h"
#include "textdisplay.h"
#include "property.h"

class Game {
  std::vector<Player*> player;
  std::vector<Board*> buildings(40);
  Dice* dice;
  Player* currentPlayer;
  int activeRim;
  TextDisplay* td;
public:
  Game();
  ~Game();
  int roll(); //////////////////////// Modified!!!!
  Board& move(int num1, int num2);
  Board& moveToCertain(Board& b);
  void nextPlayer();
  void initPlayer(string name, char playerChar); //////////// MODIFIED!!!!!!!!!!
  bool validPlayer(string name); ////////////////////
  string getOwner(const Board& b);
  void purchase(Board& b, Player& p);
  void trade(Player& p, Board& b, unsigned_int n);
  void trade(Board& b1, Board& b2, Player& p);
  void trade(unsigned_int n, Board& b, Player& p);
  void improve(Board& b, bool improve);
  void mortgage(Board& b);
  void unmortgage(Board& b);
  bool checkAssetVSLiability();
  bool checkIfBankruptcy();
  void removePlayer();
  void asset();
  void all();
  ofstream& save(string filename);
  void load(ifstream &file);
  int getActiverRim();
  void changeActiverRim();
  void auction(Property& pro);
  void nextTurn();
};

#endif
