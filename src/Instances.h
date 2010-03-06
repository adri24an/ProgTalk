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

  std::map<char *,ASTinstances> astInst;
};



 /*  
  char * getIid();
  char * getTid();
  char * getName();
  
  void setIid(char * id);
  void setTid(char * id);
  void setName(char * id);
  */
