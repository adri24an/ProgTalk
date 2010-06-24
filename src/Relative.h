#ifndef _RELATIVE_H
#define _RELATIVE_H


#include "Timestamp.h"

class Event;

//This class represents relative times.
class Relative : public Timestamp {
  protected:
    Event * reference;

    //Difference with the relative time.
    int diff;


  public:
    Relative();

    ~Relative();

};
#endif
