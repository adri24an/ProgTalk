#include "Instances.h"

Instances :: Instances(char * iid, int time)
{
    iid = NULL;
    tid = NULL;
    name = NULL;
}

Instances :: ~Instances()
{
    delete iid;
    delete tid;
    delete name;
}

Instances * Instances::getInstances()
{
    return &instances;
}

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
