#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H


class Event;

//This class is used by the parser for storaging purposes during parsing.
class Timestamp {
  protected:
    Timeref ;

    Event * ;


  public:
    int getAbsoluteTime();

};
#endif
