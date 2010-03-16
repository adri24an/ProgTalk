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
  void addMsg (char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec);

private:

  Instances * instances;
  Messages * messages;
};

#endif
