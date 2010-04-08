#ifndef INSTANCES_H
#define INSTANCES_H

#include "string.h"
#include "ASTinstances.h"
#include <iostream>
#include <map>
  
class Instances
{
  
public:

  Instances();
  ~Instances();

  //Adds a new instance
  void addInst(char * new_iid, char * new_tid, char * new_name);
  //Shows Instances data on screen
  void myPrint();

private:

  std::map<char *, ASTinstances *> astInst;
};

#endif
