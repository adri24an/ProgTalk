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
  char * getIid ();
  int getValtype ();
  int getValue ();
  void setIid (char * id);
  void setTime (int valtype, int value);

private:

  char * iid;
  Timeref * time;
};

#endif

