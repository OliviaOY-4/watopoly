#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "subject.h"
#include "observer.h"
#include "player.h"

class Board: public Subject, public Observer {
  int position;
  string name;
  vector<Player*> curPlayer;
public:
  Board(int position, string name);
  ~Board();
  string getName();
  int getPosition();
  vector<Player*> getCurPlayer();
  int getVisitorNum();
  void action(Player& p);
  void notify(Player* p);
  string gettype();
};

#endif
