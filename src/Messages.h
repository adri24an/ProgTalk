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

  Messages(char * iid, int time);
  ~Messages();

  /*Messages * getMessages();
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
  std::string destiny, int time_sent, int time_rec);*/
  
private:

  char * id;
  std::map<char *,ASTmessages> messages;
};
