#ifndef OBSERVER_H
#define OBSERVER_H

#include "player.h"

class Observer {
public:
  virtual void notify(Player* p) = 0;
};

#endif
