#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"

class Subject {
  std::vector<Observer*> observers;
public:
  void attach(Observer *o);
  void notifyObservers(Player *p);
};

#endif

