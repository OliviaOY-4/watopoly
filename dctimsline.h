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
        if (!p.getsentToDCTL) cout << "Nothing happens." << endl;
        else {
            cout << "You are in DC Tims Line." << endl;
            cout << "Roll doubles (input 0), pay $50 (input 1) or use a Roll Up the Rim cup (input 2) to leave." << endl;
            cout << "Input: ";
            int choice;
            cin >> choice;
            while (choice != 0 && choice != 1 && choice != 2) {
                cout << "Invalid input. Please try again." << endl;
                cout << "Input: ";
                cin >> choice;
            }
            if (choice == 0) {
                int dice1 = roll(6);
                int dice2 = roll(6);
                if (dice1 == dice2) {
                    cout << "You rolled doubles and left DC Tims Line." << endl;
                    p.setsentToDCTL(false);
                    p.setDCTLtimes(0);
                    p.setOSAPcollect(true);
                } else {
                    if (p.getDCTLtimes() == 2) {
                        cout << "You already stayed in DC Tims Line for 3 times. You can leave now." << endl;
                        p.setsentToDCTL(false);
                        p.setDCTLtimes(0);
                        p.setOSAPcollect(true);
                    } else {
                        cout << "Unfortunately, you will stay in DC Tims Line." << endl;
                        p.setDCTLtimes(p.getDCTLtimes() + 1);
                    }
                }
            } else if (choice == 1) {
                p.addCash(-50);
                cout << "You paid $50 and left DC Tims Line." << endl;
                p.setsentToDCTL(false);
                p.setDCTLtimes(0);
                p.setOSAPcollect(true);
            } else {
                cout << "You used a Roll Up the Rim cup and left DC Tims Line." << endl;
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
