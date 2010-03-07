#ifndef MSC_H
#define MSC_H

#include "Instances.h"
#include "Messages.h"

class MSC
{
  
public:

  MSC();
  ~MSC();
  MSC * getMSC;
  void addInst (char * newiid, char * newtid, char * name);

private:

  Instances * instances;
  Messages * messages;
};

#endif
