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
  // std::vector<Player*> curPlayer;
  std::vector<shared_ptr<Player>> curPlayer;
public:
  Board(int position, std::string name);
  virtual ~Board();
  std::string getName();
  int getPosition();
  std::shared_ptr<Player> getCurPlayer();
  int getVisitorNum();
  std::string getType();
};

#endif

