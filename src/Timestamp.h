#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class Timestamp
{
  
public:

  Timestamp(char * iid, int time);
  ~Timestamp();
  char * getIid ();
  int getTime ();
  void setIid (char * id);
  void setTime (int reltime);

private:

  char * iid;
  int time;
};

#endif

