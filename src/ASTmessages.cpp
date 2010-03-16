#include "ASTmessages.h"

ASTmessages :: ASTmessages()
{
  mid = NULL;
  sms = NULL;
  origin = NULL;
  destiny = NULL;
}

ASTmessages :: ASTmessages(char * new_mid, char * new_sms, char * new_origin, 
			   char * new_destiny, int new_time_sent, 
			   int new_time_rec)
{
  strcpy (mid, new_mid);
  strcpy (sms, new_sms);
  strcpy (origin, new_origin);
  strcpy (destiny, new_destiny);
  time_sent = new_time_sent;
  time_rec = new_time_rec;
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

