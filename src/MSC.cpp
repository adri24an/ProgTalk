#include "MSC.h"

MSC :: MSC()
  :instances(), messages()
{
}

void MSC :: addInst (char * newiid, char * newtid, char * name)
{
  instances->addInst (newiid, newtid, name);
}
