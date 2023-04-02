#ifndef TUITION_H
#define TUITION_H

#include "nonproperty.h"

class Tuition: public NonProperty {
public:
    void action(Player &p) {
        cout << "Choose between paying $300 tuition (input 0) or 10% of your total worth (input 1)." << endl;
        int choice;
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 0) p.addCash(-300);
        else {
            int worth = p.getTotalWorth();
            p.addCash(-0.1 * worth);
        }
    }
};

#endif
