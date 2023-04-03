#ifndef COOPFEE_H
#define COOPFEE_H

#include "nonproperty.h"

class CoopFee: public NonProperty {
public:
    CoopFee();
    void action(Player &p) {
        p.addCash(-150);
        std::cout << "You have paid $150 for the Coop Fee." << std::endl;
    }
};

#endif
