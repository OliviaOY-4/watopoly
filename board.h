#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "player.h"

class Board: public Subject, public Observer {
  int position;
  std::string name;
  std::string type;
  Game* game;
  std::vector<Player*> curPlayer;
public:
  Board(int position, std::string name, std::string type, Game* game);
  ~Board();
  std::string getName();
  int getPosition();
  std::vector<Player*> getCurPlayer();
  int getVisitorNum();
  std::string getType() = 0;
};

#endif

