#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "board.h"
#include "player.h"
#include "dice.h"
#include "textdisplay.h"
#include "property.h"

class Game {
  int activeRim;
  // std::vector<Player*> player;
  // std::vector<Board*> board;
  // Dice* dice;
  // Player* currentPlayer;
  // TextDisplay* td;
  std::vector<std::shared_ptr<Board>> board;
  std::vector<std::shared_ptr<Player>> player;
  std::unique_ptr<Dice> dice;
  std::unique_ptr<TextDisplay> td;
  std::shared_ptr<Player> currentPlayer;
public:
  Game();
  ~Game();
  int roll(); //////////////////////// Modified!!!!
  // void move(int num, Player *p = currentPlayer); //////////////// MODIFIED!!!!!
  void move(int num, std::shared_ptr<Player> p=nullptr); //////////////// MODIFIED!!!!!
  void nextPlayer();
  void initPlayer(std::string name, char playerChar); //////////// MODIFIED!!!!!!!!!!
  std::string getOwner(const Board& b);
  void purchase(Board& b, Player& p);
  bool isValidPlayer(std::string name); //////////////////// MODIFIED!!!!!!
  bool isValidProperty(std::string bName); /////////////////MODIFIED!!!
  Board& getBoard(std::string bName); ////////////// MODIFIED!!!!!
  Player& getPlayer(std::string name); /////////////// MODIFIED!!!!
  bool trade(Player& p, Board& b, unsigned int n); /////////////MODIFIED!!!!!
  bool trade(Player& p, Board& b_give, Board& b_receive); /////////////  MODIFIED!!!!
  bool trade(Player& p, unsigned int n, Board& b);  ///////////// MODIFIED!!!!!
  bool improve(Board& b, bool improve); //////////////// Modified!!!!!
  bool mortgage(Board& b); /////////////// MODIFIED!!!!
  bool unmortgage(Board& b); //////////// MODIFIED!!!!!!!
  bool checkAssetVSLiability();
  bool checkIfBankruptcy();
  void removePlayer();
  bool asset(); /////////// Modified!!!!!!!!
  bool all(); /////////////// MODIFIED!!!!!
  std::ofstream& save(std::string filename,std::ofstream & file);
  void load(std::ifstream &file);
  int getActiverRim();
  void setActiverRim(int n);
  void auction(Property& pro);
  void printMap();
};

#endif
