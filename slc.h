#ifndef SLC_H
#define SLC_H

#include "nonproperty.h"
#include "game.h"
#include <ctime>
#include <cstdlib>

class SLC: public NonProperty {
    int roll2(int n) {
        srand(static_cast<unsigned>(time(0)));
        int randnum = rand() % n + 1;
        return randnum;
    }
    int nextmove;
public:
    SLC(int position, std::string name): NonProperty(position, name) {}
    ~SLC() {};
    int getNextMove() override {return nextmove;}
    int action(Player &p, int cup) override {
        if (cup < 4) {
            int ran = roll2(100);
            if (ran == 1) {
                int tmp = p.getRURCup();
                p.setRURCup(tmp + 1);
                std::cout << "You got a Roll Up the Rim cup." << std::endl;
                return cup + 1;
            }
        }
        int rand = roll2(24);
        if (1 <= rand && rand <= 3) {
            nextmove = -3;
            std::cout << "You have been moved back 3 squares." << std::endl;
        } else if (4 <= rand && rand <= 7) {
            nextmove = -2;
            std::cout << "You have been moved back 2 squares." << std::endl;
        } else if (8 <= rand && rand <= 11) {
            nextmove = -1;
            std::cout << "You have been moved back 1 square." << std::endl;
        } else if (12 <= rand && rand <= 14) {
            nextmove = 1;
            std::cout << "You have been moved forward 1 square." << std::endl;
        } else if (15 <= rand && rand <= 18) {
            nextmove = 2;
            std::cout << "You have been moved forward 2 squares." << std::endl;
        } else if (19 <= rand && rand <= 22) {
            nextmove = 3;
            std::cout << "You have been moved forward 3 squares." << std::endl;
        } else if (rand == 23) {
            p.setDCTLtimes(0);
            p.setsentToDCTL(true);
            p.setPosition(10);
            p.setOSAPcollect(false);
            std::cout << "You have been sent to DC Tims Line." << std::endl;
        } else {
            p.setOSAPcollect(true);
            p.setPosition(0);
            std::cout << "You have been sent to OSAP." << std::endl;
        }
        return cup;
    }
};

#endif
