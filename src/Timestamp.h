#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H


#include "Timeref.h"

class Event;

//This class represents the time when an event occurs
class Timestamp {
  protected:
    Timeref ;

    Event * ;


  public:
    int getAbsoluteTime();

    Timestamp();

    ~Timestamp();

};
#endif
