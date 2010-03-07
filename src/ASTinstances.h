#ifndef ASTINSTANCES_H
#define ASTINSTANCES_H

struct ASTinstances
{
  
};
  
class Instances
{
  
public:

  ASTinstances();
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
