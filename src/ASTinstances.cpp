#include "ASTinstances.h"

ASTinstances :: ASTinstances()
{
    tid = NULL;
    name = NULL;
}

char * ASTinstances :: getTid()
{
    return tid;
}

char * ASTinstances :: getName()
{
    return name;
}

void * ASTinstances :: setTid(char * id)
{
    strcpy(iid, id);
}

void * ASTinstances :: setName(char * id)
{
    strcpy(iid, id);
}

