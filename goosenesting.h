#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "nonproperty.h"

class GooseNesting: public NonProperty {
public:
    GooseNesting();
    void action(Player &p) {
        cout << "Attacked by a flock of nesting geese!!! Run!!!" << endl;
    }
};

#endif
