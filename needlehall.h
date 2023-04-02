#ifndef NEEDLEHALL_H
#define NEEDLEHALL_H

#include "nonproperty.h"
#include <ctime>
#include <cstdlib>

int roll(int n) {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % n + 1;
  return randnum;
}

class NeedleHall: public NonProperty {
public:
    void action(Player &p) {
        if (game->getActiverRim() < 4) {
            int ran = roll(100);
            if (ran == 1) {
                int tmp = p.getRURCup();
                p.setRURCup(tmp + 1);
                game->setActiverRim(game->getActiverRim() + 1);
                return;
            }
        }
        int rand = roll(18);
        if (1 == rand) {
            p.addCash(-200);
        } else if (2 <= rand && rand <= 3) {
            p.addCash(-100);
        } else if (4 <= rand && rand <= 6) {
            p.addCash(-50);
        } else if (7 <= rand && rand <= 12) {
            p.addCash(25);
        } else if (13 <= rand && rand <= 15) {
            p.addCash(50);
        } else if (16 <= rand && rand <= 17) {
            p.addCash(100);
        } else {
            p.addCash(200);
        }
    }
};

#endif
