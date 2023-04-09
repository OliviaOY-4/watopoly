#ifndef TUITION_H
#define TUITION_H

#include "nonproperty.h"

class Tuition: public NonProperty {
public:
    Tuition(int position, std::string name): NonProperty(position, name) {}
    ~Tuition() {};

    int getNextMove() override {return 0;}

    int action(Player &p, int cup) override {
        std::cout << "==> " << "Choose between paying $300 tuition (input 0) or 10% of your total worth (input 1)." << std::endl;
        int choice;
        std::cout << "==> " << "Your choice: ";
        
        while (std::cin >> choice) {
            if (choice == 0) {
                // if (p.getCashAmount() < 300) {
                //     std::cout << "==> " << "You do not have $300. Choose a valid option." << std::endl  << "==> "<< "Your choice: ";
                //     continue;
                p.addCash(-300);
                std::cout << "==> " << "You have paid $300 tuition." << std::endl;
                break;
                
            } else if (choice == 1) {
                int worth = p.getTotalWorth();
                p.addCash(-0.1 * worth);
                std::cout << "==> " << "You have paid " << 0.1 * worth << " tuition." << std::endl;
                break;
            } else {
                std::cout << std::endl << "==> " << "Invalid input. Please try again." << std::endl;
                std::cout << "==> " << "Your choice: ";
            }
        }
        return cup;
    }
            
};

#endif
