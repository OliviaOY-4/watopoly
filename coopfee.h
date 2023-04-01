#ifndef COOPFEE_H
#define COOPFEE_H

#include "nonproperty.h"

class CoopFee: public NonProperty {
public:
    CoopFee();
    void action(Player *p);
};

#endif
