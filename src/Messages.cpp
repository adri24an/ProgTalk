#include "Messages.h"

Messages :: Messages()
  :astMsg()
{
}

Messages :: ~Messages()
{
}

void Messages :: addMsg(char * new_mid, char * new_sms, 
			char * new_origin, char * new_destiny, 
			int new_time_sent, int new_time_rec)
{
  std::map<int, ASTmessages *>::const_iterator
    mit (astMsg.begin()),
    mend(astMsg.end());
  ASTmessages * m = NULL;
  int id;

  if (strcmp (new_mid, "No_Info_Available"))
	{
	  for(;mit!=mend;++mit) 
		{
		  m = mit->second;
		  if (!(strcmp(m->getMid(), new_mid)))
			{
		  std::cout << "Error: the mid (" << new_mid << 
			") used in the message already exists" << std::endl;
		  exit(0);
			}
		}
	}

  m = new ASTmessages(new_mid, new_sms, new_origin, new_destiny, 
				    new_time_sent, new_time_rec);

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

int Messages :: getTime_sent(char * mid)
{
  std::map<int, ASTmessages *>::const_iterator
    mit (astMsg.begin()),
    mend(astMsg.end());
  ASTmessages * m = NULL;
  int time = 0;

  for(;mit!=mend;++mit) 
	{
	  m = mit->second;
	  if (!(strcmp(m->getMid(), mid)))
		{
		  time = m->getTime_sent();
		  return time;
		}
	}
  std::cout << 
	"Error: the mid used as a reference in the message doesn't exists" 
			<< std::endl;
  exit(0);
}

int Messages :: getTime_rec(char * mid)
{
  std::map<int, ASTmessages *>::const_iterator
    mit (astMsg.begin()),
    mend(astMsg.end());
  ASTmessages * m = NULL;
  int time = 0;

  for(;mit!=mend;++mit) 
	{
	  m = mit->second;
	  if (!(strcmp(m->getMid(), mid)))
		{
		  time = m->getTime_rec();
		  return time;
		}
	}
  std::cout << 
	"Error: the mid used as a reference in the message doesn't exists" 
			<< std::endl;
  exit(0);
}

int Messages :: msgSize()
{
  return (int) astMsg.size();
}

void Messages :: myPrint()
{
  std::map<int, ASTmessages *>::const_iterator
    mit (astMsg.begin()),
    mend(astMsg.end());
  for(;mit!=mend;++mit) 
	{
	  std::cout << mit->first << " -> ";
	  mit->second->myPrint();
	}
}
