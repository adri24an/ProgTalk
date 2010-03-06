#include "Timestamp.h"

Timestamp :: Timestamp(char * iid, int time)
{
    iid = NULL;
    time = -1;
}

Timestamp :: ~Timestamp()
{
    delete iid;
}

char * Timestamp :: getIid()
{
    return iid;
}

int Timestamp :: getTime()
{
    return time;
}

void Timestamp :: setIid(char * id)
{
    strcpy (iid, id);
}

void Timestamp :: setTime(int reltime)
{
    time = reltime;
}
