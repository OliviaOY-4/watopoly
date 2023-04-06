#ifndef GOOSENESTING_H
#define GOOSENESTING_H

#include "nonproperty.h"

class GooseNesting: public NonProperty {
public:
    GooseNesting()(int position, std::string name): NonProperty(position, name) {}
    ~GooseNesting();
    void action() override {
        std::cout << "Attacked by a flock of nesting geese!!! Run!!!" << std::endl;
    }
};

#endif
