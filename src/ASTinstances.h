#ifndef ASTINSTANCES_H
#define ASTINSTANCES_H

#include <string.h>
#include <iostream>
  
class ASTinstances
{
  
public:
  
  ASTinstances(char * new_tid, char * new_name);
  ~ASTinstances();

  //Returns tid
  char * getTid();
  //Returns name
  char * getName();
  //Sets tid value
  void setTid(char * id);
  //Sets name value
  void setName(char * id);
  //Shows instances data on screen
  void myPrint();

private:

  char * tid;
  char * name;
};

#endif
