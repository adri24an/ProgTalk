#include "Timestamp.h"

Timestamp :: Timestamp()
{
    iid = NULL;
    time = -1;
}

Timestamp :: ~Timestamp()
{
    delete iid;
}

//Returns iid
void Timestamp :: getIid()
{
    return iid;
}

//Returns time
void Timestamp :: getTime()
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
