#include "ASTinstances.h"

ASTinstances :: Instances()
{
    tid = NULL;
    name = NULL;
}

char * Instances :: getTid()
{
    return tid;
}

char * Instances :: getName()
{
    return name;
}

void * Instances :: setTid(char * id)
{
    strcpy(iid, id);
}

void * Instances :: setName(char * id)
{
    strcpy(iid, id);
}

