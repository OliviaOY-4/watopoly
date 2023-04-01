#ifndef GOTOTIMS_H
#define GOTOTIMS_H

#include "nonproperty.h"

class GoToTims: public NonProperty {
public:
    GoToTims();
    void action(Player *p);
};

#endif
