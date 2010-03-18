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
  int getTime_sent(int id);
  int getTime_rec(int id);

private:

  Instances * instances;
  Messages * messages;
};

#endif
