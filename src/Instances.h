#ifndef INSTANCES_H
#define INSTANCES_H

#include "string.h"
#include <map>

struct ASTinstances
{
  char * tid;
  char * name;
};
  
class Instances
{
  
public:

  Instances();
  ~Instances();

  //Adds a new instance
  void addInst(char * newiid, char * newtid, char * newname);

private:

  std::map<char *,struct ASTinstances> astInst;
};

#endif
