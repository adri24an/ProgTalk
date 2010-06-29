#ifndef _TIMESTG_H
#define _TIMESTG_H


class Timeref;

//This class is used by the parser for storaging purposes during parsing.
class Timestg {
  protected:
    Timeref * timeref;

    char * iid;


  public:
    Timestg();

    ~Timestg();

};
#endif
