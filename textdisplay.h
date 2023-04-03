#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "player.h"

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
public:
  void notify(Player* p);
};

#endif

