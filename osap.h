#ifndef OSAP_H
#define OSAP_H

#include "nonproperty.h"

class OSAP: public NonProperty {
public:
    void action(Player &p) {
        if (p.getOSAPcollect()) p.addCash(200);
        std::cout << "Collect OSAP, cash +200." << std::endl;
    }
};

#endif
