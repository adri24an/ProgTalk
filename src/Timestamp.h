#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Timeref.h"

class Timestamp
{
  
public:

  Timestamp(char * new_iid, Timeref * new_time);
  ~Timestamp();

  //Returns iid
  char * getIid ();
  //Returns the atribute Valtype of time object
  int getValtype ();
  //Returns the atribute Value of time object
  int getValue ();
  //Sets iid value
  void setIid (char * id);
  //Sets Valtype and Value values of time object
  void setTime (int valtype, int value);

private:

  char * iid;
  Timeref * time;
};

#endif

