#ifndef ASTMESSAGES_H
#define ASTMESSAGES_H

#include <string.h>
#include <iostream>
  
class ASTmessages
{
  
public:
  
  ASTmessages(char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec);
  ~ASTmessages();

  //Returns the mid of the message
  char * getMid();
  //Returns the sms of the message
  char * getSms();
  //Returns the origin of the message
  char * getOrigin();
  //Returns the destiny of the message
  char * getDestiny();
  //Returns the time when the message was sent
  int getTime_sent();
  //Returns the time when the message was received
  int getTime_rec();
  //Sets the value of mid
  void setMid(char * id);
  //Sets the value of sms
  void setSms(char * id);
  //Sets the value of origin
  void setOrigin(char * id);
  //Sets the value of destiny
  void setDestiny(char * id);
  //Sets the value of time_sent
  void setTime_sent(int id);
  //Sets the value of time_rec
  void setTime_rec(int id);
  //Shows messages data on screen
  void myPrint();

private:

  char * mid;
  char * sms;
  char * origin;
  char * destiny;
  int time_sent;
  int time_rec;
};

#endif
