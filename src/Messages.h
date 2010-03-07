#ifndef MESSAGES_H
#define MESSAGES_H

#include "string.h"
#include <map>

struct ASTmessages
{
  char * mid;
  char * sms;
  char * origin;
  char * destiny;
  int time_sent;
  int time_rec;
};

class Messages
{
  
public:

  Messages();
  ~Messages();

  //Adds a new message
  void addMsg(char * newmid, char * newsms, char * neworigin,
	      char * newdestiny, int newtime_sent, int newtime_rec);
  
private:

  std::map<char *, ASTmessages> ASTmsg;
};

#endif
