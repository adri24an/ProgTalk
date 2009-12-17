#include "Event.h"
#include <iostream>

#include <string.h>

//------------------------------------------------------------------
// Class Event
//------------------------------------------------------------------

Event :: Event (char * n1, int t1, char * n2, int t2, char * text)
{
  int aux = 0;

  this -> name1 = new char[strlen(n1)+1];
  strcpy (this -> name1, n1);
  this -> time1 = t1;
  this -> name2 = new char[strlen(n2)+1];
  strcpy (this -> name2, n2);
  this -> time2 = t2;
  this -> text = new char[strlen(text)+1];
  strcpy (this -> text, text);
}

Event :: ~Event()
{
  delete [] name1;
  delete [] name2;
  delete [] text;
}

char * Event :: GetEntity1Name ()
{
  return name1;
}

int Event :: GetEntity1Time ()
{
  return time1;
}

char * Event :: GetEntity2Name ()
{
  return name2;
}

int Event :: GetEntity2Time ()
{
  return time2;
}

char * Event :: GetText ()
{
  return text;
}
