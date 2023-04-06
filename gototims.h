#ifndef GOTOTIMS_H
#define GOTOTIMS_H

#include "nonproperty.h"

class GoToTims: public NonProperty {
public:
    GoToTims(int position, std::string name): NonProperty(position, name) {}
    ~GoToTims();
    void action(Player &p) override {
        p.setsentToDCTL(true);
        p.setDCTLtimes(0);
        p.setPosition(10);
        p.setOSAPcollect(false);
        std::cout << "You have been sent to DC Tims Line." << std::endl;
        //move???
    }
};

#endif
