#include "ASTinstances.h"

ASTinstances :: ASTinstances()
{
    tid = NULL;
    name = NULL;
}

ASTinstances :: ASTinstances(char * new_tid, char * new_name)
{
  strcpy (tid, new_tid);
  strcpy (name, new_name);
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

