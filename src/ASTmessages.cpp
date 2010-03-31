#include "ASTmessages.h"

ASTmessages :: ASTmessages(char * new_mid, char * new_sms, char * new_origin, 
						   char * new_destiny, int new_time_sent, 
						   int new_time_rec)
{
  mid = new_mid;
  sms = new_sms;
  origin = new_origin;
  destiny = new_destiny;
  time_sent = new_time_sent;
  time_rec = new_time_rec;
}

ASTmessages :: ~ASTmessages()
{
  delete mid;
  delete sms;
  delete origin;
  delete destiny;
}

char * ASTmessages :: getMid()
{
    return mid;
}

char * ASTmessages :: getSms()
{
    return sms;
}

char * ASTmessages :: getOrigin()
{
    return origin;
}

char * ASTmessages :: getDestiny()
{
    return destiny;
}

int ASTmessages :: getTime_sent()
{
    return time_sent;
}

int ASTmessages :: getTime_rec()
{
    return time_rec;
}

void ASTmessages :: setMid(char * id)
{
    strcpy(mid, id);
}
void ASTmessages :: setSms(char * id)
{
    strcpy(sms, id);
}
void ASTmessages :: setOrigin(char * id)
{
    strcpy(origin, id);
}
void ASTmessages :: setDestiny(char * id)
{
    strcpy(destiny, id);
}
void ASTmessages :: setTime_sent(int id)
{
    time_sent = id;
}
void ASTmessages :: setTime_rec(int id)
{
    time_rec = id;
}

