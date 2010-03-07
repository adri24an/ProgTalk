#ifndef ASTMESSAGES_H
#define ASTMESSAGES_H

#include <string.h>
  
class ASTmessages
{
  
public:
  
  ASTmessages();
  ASTmessages(char * new_mid, char * new_sms, char * new_origin, 
	      char * new_destiny, int new_time_sent, int new_time_rec);
  ~ASTmessages();

  char * getMid();
  char * getSms();
  char * getOrigin();
  char * getDestiny();
  int getTime_sent();
  int getTime_rec();

  void setMid(char * id);
  void setSms(char * id);
  void setOrigin(char * id);
  void setDestiny(char * id);
  void setTime_sent(int id);
  void setTime_rec(int id);

private:

  char * mid;
  char * sms;
  char * origin;
  char * destiny;
  int time_sent;
  int time_rec;
};

#endif
