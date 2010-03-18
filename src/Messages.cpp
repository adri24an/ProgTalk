#include "Messages.h"

Messages :: Messages()
{
}

void Messages :: addMsg(char * new_mid, char * new_sms, 
			char * new_origin, char * new_destiny, 
			int new_time_sent, int new_time_rec)
{
  ASTmessages * m = new ASTmessages(new_mid, new_sms, new_origin, new_destiny, 
				    new_time_sent, new_time_rec);
  int id;

  if (astMsg.empty())
  {
    astMsg[0] = m;
  }
  else
  {
    id = (int) astMsg.size();
    astMsg[id] = m;
  }
}

int Messages :: getTime_sent(int id)
{
  ASTmessages * m = astMsg.find(id)->second;
  int time = m->getTime_sent();

  return time;
}

int Messages :: getTime_rec(int id)
{
  ASTmessages * m = astMsg.find(id)->second;
  int time = m->getTime_rec();

  return time;
}
