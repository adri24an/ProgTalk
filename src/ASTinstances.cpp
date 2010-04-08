#include "ASTinstances.h"

ASTinstances :: ASTinstances(char * new_tid, char * new_name)
{
  tid = new_tid;
  name = new_name;
}

ASTinstances :: ~ASTinstances()
{
  delete tid;
  delete name;
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

void ASTinstances :: myPrint()
{
  std::cout << tid << " " << name << std::endl;
}

