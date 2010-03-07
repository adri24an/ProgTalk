#ifndef ASTINSTANCES_H
#define ASTINSTANCES_H

#include <string.h>
  
class ASTinstances
{
  
public:
  
  ASTinstances();
  ASTinstances(char * new_tid, char * new_name);
  ~ASTinstances();

  char * getTid();
  char * getName();
  
  void setTid(char * id);
  void setName(char * id);

private:

  char * tid;
  char * name;
};

#endif
