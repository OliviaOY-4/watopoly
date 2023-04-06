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
  int activeRim;
  std::vector<Player*> player;
  std::vector<Board*> board;
  Dice* dice;
  Player* currentPlayer;
  TextDisplay* td;
public:
  Game();
  ~Game();
  int roll(); //////////////////////// Modified!!!!
  void move(int num, Player *p = currentPlayer); //////////////// MODIFIED!!!!!
  void nextPlayer();
  void initPlayer(std::string name, char playerChar); //////////// MODIFIED!!!!!!!!!!
  string getOwner(const Board& b);
  void purchase(Board& b, Player& p);
  bool isValidPlayer(std::string name); //////////////////// MODIFIED!!!!!!
  bool isValidProperty(std::string bName); /////////////////MODIFIED!!!
  Board& getBoard(std::string bName); ////////////// MODIFIED!!!!!
  Player& getPlayer(std::string name); /////////////// MODIFIED!!!!
  bool trade(Player& p, Board& b, unsigned_int n); /////////////MODIFIED!!!!!
  bool trade(Player& p, Board& b_give, Board& b_receive); /////////////  MODIFIED!!!!
  bool trade(Player& p, unsigned_int n, Board& b);  ///////////// MODIFIED!!!!!
  bool improve(Board& b, bool improve); //////////////// Modified!!!!!
  bool mortgage(Board& b); /////////////// MODIFIED!!!!
  bool unmortgage(Board& b); //////////// MODIFIED!!!!!!!
  bool checkAssetVSLiability();
  bool checkIfBankruptcy();
  void removePlayer();
  bool asset(); /////////// Modified!!!!!!!!
  bool all(); /////////////// MODIFIED!!!!!
  ofstream& save(std::string filename);
  void load(ifstream &file);
  int getActiverRim();
  void setActiverRim(int n);
  void auction(Property& pro);
};

#endif
