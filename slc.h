#ifndef SLC_H
#define SLC_H

#include "nonproperty.h"
#include "game.h"
#include <ctime>
#include <cstdlib>

int roll() {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % 24 + 1;
  return randnum;
}

class SLC: public NonProperty {
public:
    void action(Player &p) {
        int rand = roll();
        if (1 <= rand && rand <= 3) {
            int to = p.getPosition() - 3;
            game->move(p, to);
        } else if (4 <= rand && rand <= 7) {
            int to = p.getPosition() - 2;
            game->move(p, to);
        } else if (8 <= rand && rand <= 11) {
            int to = p.getPosition() - 1;
            game->move(p, to);
        } else if (12 <= rand && rand <= 14) {
            int to = p.getPosition() + 1;
            game->move(p, to);
        } else if (15 <= rand && rand <= 18) {
            int to = p.getPosition() + 2;
            game->move(p, to);
        } else if (19 <= rand && rand <= 22) {
            int to = p.getPosition() + 3;
            game->move(p, to);
        } else if (rand == 23) {
            p.setDCTLtimes();
            game->move(p, 10);
        } else {
            p.setOSAPcollect(true);
            game->move(p, 0);
        }
    }
};

#endif
