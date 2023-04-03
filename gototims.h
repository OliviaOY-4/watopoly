#ifndef GOTOTIMS_H
#define GOTOTIMS_H

#include "nonproperty.h"

class GoToTims: public NonProperty {
public:
    void action(Player &p) {
        p.setsentToDCTL(true);
        p.setDCTLtimes(0);
        p.setPosition(10);
        p.setOSAPcollect(false);
        std::cout << "You have been sent to DC Tims Line." << std::endl;
    }
};

#endif
