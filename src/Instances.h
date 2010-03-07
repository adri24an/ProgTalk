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
  void addInst(char * new_iid, char * new_tid, char * new_name);

private:

  std::map<char *, ASTinstances *> astInst;
};

#endif
