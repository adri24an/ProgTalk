#include "ASTinstances.h"

ASTinstances :: ASTinstances()
{
    tid = NULL;
    name = NULL;
}

ASTinstances :: ASTinstances(char * newtid, char * newname)
{
  strcpy (tid, newtid);
  strcpy (name, newname);
}

char * ASTinstances :: getTid()
{
    return tid;
}

char * ASTinstances :: getName()
{
    return name;
}

void ASTinstances :: setTid(char * id)
{
    strcpy(tid, id);
}

void ASTinstances :: setName(char * id)
{
    strcpy(name, id);
}

