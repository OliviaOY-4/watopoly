#ifndef TESTDISPLAY_H
#define TESTDISPLAY_H

#include <iostream>
#include <vector>
#include "player.h"

class TextDisplay: public Observer {
  vector<vector<char>> theDisplay;
public:
  void notify(Player* p);
};

#endif

