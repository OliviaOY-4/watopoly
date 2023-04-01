#ifndef TUITION_H
#define TUITION_H

#include "nonproperty.h"

class Tuition: public NonProperty {
public:
    Tuition();
    void action(Player *p);
};

#endif
