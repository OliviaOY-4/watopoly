#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "player.h"

class TextDisplay{
  std::vector<string> boardMap;
  
public:
  TextDisplay();
  void addPlayer(int pos, std::string name);
  void deletePlayer(int pos, std::string name);
  void addImprovement(int pos);
  void drawBoard(std::ostream& out);
}

ostream& operator<<(ostream& out, const TextDisplay& td);

#endif

