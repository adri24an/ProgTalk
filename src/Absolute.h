#ifndef _ABSOLUTE_H
#define _ABSOLUTE_H


#include "Timestamp.h"

//This class represents absolute times.
class Absolute : public Timestamp {
  protected:
    int time;


  public:
    Absolute();

    ~Absolute();

};
#endif
