#ifndef _RELATIVE_H
#define _RELATIVE_H


#include "Timestamp.h"

class Event;

//This class represents relative times.
class Relative : public Timestamp {
  protected:
    Event * reference;

    int diff;


  public:
    Relative();

    ~Relative();

};
#endif
