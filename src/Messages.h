#ifndef MESSAGES_H
#define MESSAGES_H

#include "string.h"
#include <map>
#include <iostream>
#include <stdlib.h>
#include "ASTmessages.h"

class Messages
{
  
public:

  Messages();
  ~Messages();

  //Adds a new message
  void addMsg(char * new_mid, char * new_sms, char * new_origin,
	      char * new_destiny, int new_time_sent, int new_time_rec);
  //Returns the time when the message with the given mid was sent
  int getTime_sent(char * mid);
  //Returns the time when the message with the given mid was received
  int getTime_rec(char * mid);
  //Returns the time when the message with the given id was sent
  int getTime_sent(int id);
  //Returns the time when the message with the given id was received
  int getTime_rec(int id);
  //Returns the number of messages storaged
  int msgSize();
  //Shows Messages data on screen
  void myPrint();
  
private:

  std::map<int, ASTmessages *> astMsg;
};

#endif
