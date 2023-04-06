#ifndef OSAP_H
#define OSAP_H

#include "nonproperty.h"

class OSAP: public NonProperty {
public:
    OSAP(int position, std::string name): NonProperty(position, name) {}
    ~OSAP();
    void action(Player &p) override {
        if (p.getOSAPcollect()){
            p.addCash(200);
            std::cout << "Collect OSAP, collected $200." << std::endl;
        }
    }
};

#endif
