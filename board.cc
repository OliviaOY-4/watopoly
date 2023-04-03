#include "board.h"

Board::Board(int position, string name, string type, Game* game): position{position}, name{name}, type{type}, game{game} {}

Board::~Board() {
  delete game;
  for (auto i:curPlayer) {
    delete i;
  }
}

string Board::getName() {
  return name;
}

string Board::getType() {
  return type;
}

int Board::getPosition() {
  return position;
}

vector<Player*> Board::getCurPlayer() {
  return curPlayer;
}

int Board::getVisitorNum() {
  return curPlayer.size();
}


