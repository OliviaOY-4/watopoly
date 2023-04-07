#ifndef TUITION_H
#define TUITION_H

#include "nonproperty.h"

class Tuition: public NonProperty {
public:
    Tuition(int position, std::string name): NonProperty(position, name) {}
    ~Tuition() {};
    void action(Player &p) override {
        std::cout << "Choose between paying $300 tuition (input 0) or 10% of your total worth (input 1)." << std::endl;
        int choice;
        std::cout << "Your choice: ";
        std::cin >> choice;
        while (choice != 0 && choice != 1) {
            std::cout << std::endl << "Invalid input. Please try again." << std::endl;
            std::cout << "Input: ";
            std::cin >> choice;
        }
        if (choice == 0) {
            p.addCash(-300);
            std::cout << "You have paid $300 tuition." << std::endl;
        } else {
            int worth = p.getTotalWorth();
            p.addCash(-0.1 * worth);
            std::cout << "You have paid " << 0.1 * worth << "tuition." << std::endl;
        }
         
    }
};

#endif
