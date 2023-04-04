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
  std::vector<Board*> buildings;
  std::vector<Board*> board;
  Dice* dice;
  Player* currentPlayer;
  int activeRim;
  TextDisplay* td;
public:
  Game();
  ~Game();
  int roll(); //////////////////////// Modified!!!!
  Board& move(int num, Player *p = currentPlayer); //////////////// MODIFIED!!!!!
  Board& moveToCertain(Board& b);
  void nextPlayer();
  void initPlayer(std::string name, char playerChar); //////////// MODIFIED!!!!!!!!!!
  string getOwner(const Board& b);
  void purchase(Board& b, Player& p);
  bool isValidPlayer(std::string name); //////////////////// MODIFIED!!!!!!
  bool isValidProperty(std::string b); /////////////////MODIFIED!!!
  Board& getBoard(std::string board); ////////////// MODIFIED!!!!!
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
  void changeActiverRim();
  void auction(Property& pro);
};

#endif
