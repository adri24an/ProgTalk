#include "Timestamp.h"

Timestamp :: Timestamp(char * new_iid, Timeref * new_time)
{
    iid = new_iid;
    time = new_time;
}

Timestamp :: ~Timestamp()
{
    delete iid;
    delete time;
}

char * Timestamp :: getIid()
{
    return iid;
}

int Timestamp :: getValtype()
{
    return time->getValtype();
}

int Timestamp :: getValue()
{
    return time->getValue();
}

void Timestamp :: setIid(char * id)
{
    strcpy (iid, id);
}

void Timestamp :: setTime(int new_valtype, int new_value)
{
    time->setValtype(new_valtype);
    time->setValue(new_value);
}
