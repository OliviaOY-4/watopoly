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
        while (choice != 0 && choice != 1) {
            cout << "Invalid input. Please try again." << endl;
            cout << "Input: ";
            cin >> choice;
        }
        if (choice == 0) p.addCash(-300);
        cout << "You have paid $300 tuition." << endl;
        else {
            int worth = p.getTotalWorth();
            p.addCash(-0.1 * worth);
        } cout << "You have paid " << 0.1 * worth << "tuition." << endl;
    }
};

#endif
