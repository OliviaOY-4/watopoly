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
#include "academicbuilding.h"
#include "residence.h"
#include "gym.h"
#include "nonproperty.h"
#include "slc.h"
#include "needlehall.h"
#include "osap.h"
#include "tuition.h"
#include "coopfee.h"
#include "gototims.h"
#include "goosenesting.h"
#include "dctimsline.h"
#include <fstream>


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
  std::shared_ptr<Player> currentPlayer;
  std::unique_ptr<TextDisplay> td;
public:
  Game();
  ~Game();
  int roll(); 
  // void move(int num, Player *p = currentPlayer); 
  void move(int num, std::shared_ptr<Player> p = nullptr); 
  void nextPlayer();
  void initPlayer(std::string name); 
  std::shared_ptr<Player> getOwner(const Board& b);
  void purchase(std::string b, Player& p);
  bool isValidPlayer(std::string name); 
  bool isValidProperty(std::string bName); 
  Board& getBoard(std::string bName); 
  Player& getPlayer(std::string name); 
  bool trade(Player& p, std::string b, unsigned int n); 
  bool trade(Player& p, std::string b_give, std::string b_receive); 
  bool trade(Player& p, unsigned int n, std::string b);  
  bool improve(Board& b, bool improve); 
  bool mortgage(Board& b); 
  bool unmortgage(Board& b); 
  bool checkAssetVSLiability();
  bool checkIfBankruptcy();
  void removePlayer();
  bool asset(); 
  bool all(); 
  std::ofstream save(std::string filename);
  void load(std::ifstream &file);
  int getActiverRim();
  void setActiverRim(int n);
  void auction(std::string pro);
  void printMap();
};

#endif
