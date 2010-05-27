#ifndef _RELATIVE_H
#define _RELATIVE_H


#include "Timestamp.h"

class Event;

class Relative : public Timestamp {
  protected:
    int diff;

    Event * ;

};
#endif
