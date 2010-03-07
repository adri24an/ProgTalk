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
  void addMsg(int id, char * new_mid, char * new_sms, char * new_origin,
	      char * new_destiny, int new_time_sent, int new_time_rec);
  
private:

  std::map<int, ASTmessages> astMsg;
};

#endif
