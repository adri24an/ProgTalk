#include "Messages.h"

Messages :: Messages()
{
}

void Messages :: addMsg(int id, char * new_mid, char * new_sms, 
			char * new_origin, char * new_destiny, 
			int new_time_sent, int new_time_rec)
{
  ASTmessages * m;

  if(astMsg.find(id) == astMsg.end())
    {
      m = new ASTmessages(new_mid, new_sms, new_origin, new_destiny, 
			  new_time_sent, new_time_rec);
      astMsg[id] = m;
    }
  else
    {
	std::cout << "Error: The message already exists." << std::endl;
    }
}
