#include "game.h"
using namespace std;

Game::Game() {
  
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