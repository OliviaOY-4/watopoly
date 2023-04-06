#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <memory>
#include "player.h"
class Player;

class Board {
  int position;
  std::string name;
  std::string type;
  // std::vector<Player*> curPlayer;
  std::vector<std::shared_ptr<Player>> curPlayer;
public:
  Board(int position, std::string name);
  virtual ~Board();
  std::string getName();
  int getPosition();
  std::vector<std::shared_ptr<Player>> getCurPlayer();
  int getVisitorNum();
  std::string getType();
  virtual std::shared_ptr<Player> getOwner() const = 0;
  virtual int getPrice() const = 0;
  virtual int getVisitPrice(Player& visitor) const = 0;
};

#endif

