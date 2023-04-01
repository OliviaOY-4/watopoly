#ifndef SUBJECT_H
#define SUBJECT_H

class Subject {
  vector<Observer*> observers;
public:
  void attach(Observer *o);
  void notifyObservers(Player *p);
};

#endif

