#ifndef OSAP_H
#define OSAP_H

#include "nonproperty.h"

class OSAP: public NonProperty {
public:
    OSAP();
    void action(Player *p);
};

#endif
