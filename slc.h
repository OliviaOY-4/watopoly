#ifndef SLC_H
#define SLC_H

#include "nonproperty.h"

class SLC: public NonProperty {
public:
    SLC();
    void action(Player *p);
};

#endif
