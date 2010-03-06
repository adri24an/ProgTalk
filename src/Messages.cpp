#include "Messages.h"

Messages :: Messages(char * iid, int time)
{
    id = NULL;
    mid = NULL;
    sms = NULL;
    origin = NULL;
    destiny = NULL;
    time_sent = -1;
    time_rec = -1;
}

Messages :: ~Messages()
{
    delete id;
    delete mid;
    delete sms;
    delete origin;
    delete destiny;
}

Messages * Messages::getMessages()
{
    return &messages;
}

char * Messages :: getId()
{
    return id;
}

char * Messages :: getMid()
{
    return mid;
}

char * Messages :: getSms()
{
    return sms;
}

char * Messages :: getOrigin()
{
    return origin;
}

char * Messages :: getDestiny()
{
    return destiny;
}

int Messages :: getTime_sent()
{
    return time_sent;
}

int Messages :: getTime_rec()
{
    return time_rec;
}

void Messages :: setId(char * identifier)
{
    strcpy(id, identifier);
}

void Messages :: setMid(char * identifier)
{
    strcpy(mid, identifier);
}

void Messages :: setSms(char * identifier)
{
    strcpy(sms, identifier);
}

void Messages :: setOrigin(char * identifier)
{
    strcpy(origin, identifier);
}

void Messages :: setDestiny(char * identifier)
{
    strcpy(destiny, identifier);
}
