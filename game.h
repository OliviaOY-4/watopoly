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
  Board& move(Player *p = currentPlayer, int num);
  Board& moveToCertain(Board& b);
  void nextPlayer();
  void initPlayer(std::string name, char playerChar); //////////// MODIFIED!!!!!!!!!!
  bool isValidPlayer(std::string name); //////////////////// MODIFIED!!!!!!
  std::string getOwner(const Board& b);
  bool isValidBoard(std::string b); /////////////////MODIFIED!!!!
  void purchase(Board& b, Player& p);
  bool trade(std::string player, std::string board, std::unsigned_int n); /////////////MODIFIED!!!!!
  bool trade(std::string player, std::string board1, std::string board2); /////////////  MODIFIED!!!!
  bool trade(std::string player, std::unsigned_int n, std::string b);  ///////////// MODIFIED!!!!!
  void improve(Board& b, bool improve);
  void mortgage(Board& b);
  void unmortgage(Board& b);
  bool checkAssetVSLiability();
  bool checkIfBankruptcy();
  void removePlayer();
  void asset();
  void all();
  ofstream& save(std::string filename);
  void load(ifstream &file);
  int getActiverRim();
  void changeActiverRim();
  void auction(Property& pro);
  void nextTurn();
};

#endif
