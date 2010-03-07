#ifndef ASTINSTANCES_H
#define ASTINSTANCES_H
  
class ASTinstances
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
