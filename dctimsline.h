#ifndef DCTIMSLINE_H
#define DCTIMSLINE_H

#include "nonproperty.h"

int roll(int n) {
  srand(static_cast<unsigned>(time(0)));
  int randnum = rand() % n + 1;
  return randnum;
}

class DCTimsLine: public NonProperty {
public:
    DCTimsLine();
    void action(Player &p) {
        if (!p.getsentToDCTL) std::cout << "Nothing happens." << std::endl;
        else {
            std::cout << "You are in DC Tims Line." << std::endl;
            std::cout << "Roll doubles (input 0), pay $50 (input 1) or use a Roll Up the Rim cup (input 2) to leave." << std::endl;
            std::cout << "Input: ";
            int choice;
            std::cin >> choice;
            while (choice != 0 && choice != 1 && choice != 2) {
                std::cout << "Invalid input. Please try again." << std::endl;
                std::cout << "Input: ";
                std::cin >> choice;
            }
            if (choice == 0) {
                int dice1 = roll(6);
                int dice2 = roll(6);
                if (dice1 == dice2) {
                    std::cout << "You rolled doubles and left DC Tims Line." << std::endl;
                    p.setsentToDCTL(false);
                    p.setDCTLtimes(0);
                    p.setOSAPcollect(true);
                } else {
                    if (p.getDCTLtimes() == 2) {
                        std::cout << "You already stayed in DC Tims Line for 3 times. You can leave now." << std::endl;
                        p.setsentToDCTL(false);
                        p.setDCTLtimes(0);
                        p.setOSAPcollect(true);
                    } else {
                        std::cout << "Unfortunately, you will stay in DC Tims Line." << std::endl;
                        p.setDCTLtimes(p.getDCTLtimes() + 1);
                    }
                }
            } else if (choice == 1) {
                p.addCash(-50);
                std::cout << "You paid $50 and left DC Tims Line." << std::endl;
                p.setsentToDCTL(false);
                p.setDCTLtimes(0);
                p.setOSAPcollect(true);
            } else {
                std::cout << "You used a Roll Up the Rim cup and left DC Tims Line." << std::endl;
                p.setsentToDCTL(false);
                p.setDCTLtimes(0);
                p.setRURCup(p.getRURCup() - 1);
                game->setActiverRim(game->getActiverRim() - 1);
                p.setOSAPcollect(true);
            }
        }
    }
};

#endif
