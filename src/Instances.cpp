#include "Instances.h"

Instances :: Instances()
{
    iid = NULL;
}

Instances :: ~Instances()
{
    delete iid;
}

/*
char * Instances :: getIid()
{
    return iid;
}

char * Instances :: getTid()
{
    return tid;
}

char * Instances :: getName()
{
    return name;
}

void Instances :: setIid(char * id)
{
    strcpy(iid, id);
}

void * Instances :: setTid(char * id)
{
    strcpy(iid, id);
}

void * Instances :: setName(char * id)
{
    strcpy(iid, id);
}
*/
