#include "MSC.h"

MSC :: MSC()
  :instances(), messages()
{
}

void MSC :: addInst (char * newiid, char * newtid, char * name)
{
  instances->addInst (newiid, newtid, name);
}

void MSC :: addMsg (int id, char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec)
{
  messages->addMsg (id, new_mid, new_sms, new_origin, new_destiny, 
		    new_time_sent, new_time_rec);
}
