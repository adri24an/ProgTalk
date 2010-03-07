#ifndef INSTANCES_H
#define INSTANCES_H

#include "string.h"
#include "ASTinstances.h"
#include <map>
  
class Instances
{
  
public:

  Instances();
  ~Instances();

  //Adds a new instance
  void addInst(char * newiid, char * newtid, char * newname);

private:

  std::map<char *, ASTinstances *> astInst;
};

#endif
