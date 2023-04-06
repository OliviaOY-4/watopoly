#ifndef NEEDLEHALL_H
#define NEEDLEHALL_H

#include "nonproperty.h"
#include <ctime>
#include <cstdlib>

int rollnh(int n) {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % n + 1;
  return randnum;
}

class NeedleHall: public NonProperty {
public:
    NeedleHall(int position, std::string name): NonProperty(position, name) {}
    ~NeedleHall();
    void action(Player &p) override {return;}
    int nhaction(Player &p, int n) {
        if (n < 4) {
            int ran = rollnh(100);
            if (ran == 1) {
                int tmp = p.getRURCup();
                p.setRURCup(tmp + 1);
                std::cout << "You gain a Roll Up the Rim cup." << std::endl;
                return n + 1;
            }
        }
        int rand = rollnh(18);
        if (1 == rand) {
            p.addCash(-200);
            std::cout << "You lose $200 savings" << std::endl;
        } else if (2 <= rand && rand <= 3) {
            p.addCash(-100);
            std::cout << "You lose $100 savings" << std::endl;
        } else if (4 <= rand && rand <= 6) {
            p.addCash(-50);
            std::cout << "You lose $50 savings" << std::endl;
        } else if (7 <= rand && rand <= 12) {
            p.addCash(25);
            std::cout << "You gain $25 savings" << std::endl;
        } else if (13 <= rand && rand <= 15) {
            p.addCash(50);
            std::cout << "You gain $50 savings" << std::endl;
        } else if (16 <= rand && rand <= 17) {
            p.addCash(100);
            std::cout << "You gain $100 savings" << std::endl;
        } else {
            p.addCash(200);
            std::cout << "You gain $200 savings" << std::endl;
        }
    }
};

#endif
