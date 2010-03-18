#include "MSC.h"

MSC :: MSC()
  :instances(), messages()
{
}

void MSC :: addInst (char * newiid, char * newtid, char * name)
{
  instances->addInst (newiid, newtid, name);
}

void MSC :: addMsg (char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec)
{
  messages->addMsg (new_mid, new_sms, new_origin, new_destiny, 
		    new_time_sent, new_time_rec);
}
int MSC :: getTime_sent(int id)
{
  int time = messages->getTime_sent(id);

  return time;
}

int MSC :: getTime_rec(int id)
{
  int time = messages->getTime_rec(id);

  return time;
}
