#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "nonproperty.h"

class GooseNesting: public NonProperty {
public:
    GooseNesting();
    void action() {
        std::cout << "Attacked by a flock of nesting geese!!! Run!!!" << std::endl;
    }
};

#endif
