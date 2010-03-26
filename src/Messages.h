#ifndef MESSAGES_H
#define MESSAGES_H

#include "string.h"
#include <map>
#include <iostream>
#include "ASTmessages.h"

class Messages
{
  
public:

  Messages();
  ~Messages();

  //Adds a new message
  void addMsg(char * new_mid, char * new_sms, char * new_origin,
	      char * new_destiny, int new_time_sent, int new_time_rec);
  int getTime_sent(int id);
  int getTime_rec(int id);
  int msgSize();
  
private:

  std::map<int, ASTmessages *> astMsg;
};

#endif
