#include "string.h"

class Messages
{
  
public:

  Messages();
  ~Messages();

  Messages * getMessages();
  char * getId();
  char * getMid();
  char * getSms();
  char * getOrigin();
  char * getDestiny();

  void setId(char * identifier);
  void setMid(char * identifier);
  void setSms(char * identifier);
  void setOrigin(char * identifier);
  void setDestiny(char * identifier);

  //Adds a new message
  void addMsg(std::string mid, std::string sms, std::string origin,
		  std::string destiny, int time_sent, int time_rec);
  
private:

  char * id;
  char * mid;
  char * sms;
  char * origin;
  char * destiny;
  int time_sent;
  int time_rec;
};
