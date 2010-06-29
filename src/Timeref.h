#ifndef _TIMEREF_H
#define _TIMEREF_H


//This class is used by the parser for storaging purposes during parsing.
class Timeref {
  protected:
    //This represents if the time is absolute or relative
    int valtype;

    //This represents absolute time when the time is absolute or the diff 
    //when the time is relative
    int value;

    //This represents if the relative time depends on sending or receipt.
    //receiving = 1 or sending = 2
    //
    //when the time is absolute, this value is 0.
    int mode;

    //This represents the mid of the message that references the relative time.
    char * ref;


  public:
    Timeref();

    ~Timeref();

};
#endif
