#ifndef _TIMEREF_H
#define _TIMEREF_H


#include "Timestamp.h"

class MSC;
class Timestg;

//This class is used by the parser for storaging purposes during parsing.
class Timeref {
  protected:
    Timestamp ;

    //this represents if the time is absolute or relative
    int valtype;

    //this represents absolute time when the time is absolute or the diff when the time is relative
    int value;

    MSC * ;

    Timestg * ;

    //this represents if the relative time depends on sending or receipt.
    //receiving = 1 or sending = 2
    int mode;

    //this represents the mid of the message that references the relative time.
    char * ref;


  public:
    Timeref();

    ~Timeref();

};
#endif
