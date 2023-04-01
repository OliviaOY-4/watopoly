#ifndef NEEDLEHALL_H
#define NEEDLEHALL_H

#include "nonproperty.h"

class NeedleHall: public NonProperty {
public:
    NeedleHall();
    void action(Player *p);
};

#endif
