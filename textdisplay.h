#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include <iostream>
#include <vector>
#include "player.h"
#include <utility>

class TextDisplay{
  std::vector<string> boardMap;
  vector<pair<int,int>> playerpos;
  vector<pair<int,int>> impropos;
  
public:
  TextDisplay();
  void addPlayer(int pos, char symbol);
  void deletePlayer(int pos, char symbol);
  void addImprovement(Board& a);
  void removeImprovement(Board& a);
  void drawBoard(std::ostream& out, vector<Player*> player, vector<board*> board);
}

#endif

