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
  std::vector<Player*> curPlayer;
public:
  Board(int position, std::string name);
  virtual ~Board()=0;
  std::string getName();
  int getPosition();
  std::vector<Player*> getCurPlayer();
  int getVisitorNum();
  std::string getType();
};

#endif

