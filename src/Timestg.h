#ifndef _TIMESTG_H
#define _TIMESTG_H


class MSC;
class Timeref;

//This class is used by the parser for storaging purposes during parsing.
class Timestg {
  protected:
    MSC * ;

    Timeref * ;

    Parser * ;

    char * iid;


  public:
    Timestg();

    ~Timestg();

};
#endif
