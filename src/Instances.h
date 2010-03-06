#include "string.h"
#include <map>

struct ASTintances
{
  char * tid;
  char * name;
};
  

class Instances
{
  
public:

  Instances();
  ~Instances();

  /*  Instances * getInstances();
  char * getIid();
  char * getTid();
  char * getName();
  
  void setIid(char * id);
  void setTid(char * id);
  void setName(char * id);

  //Adds a new instance (because vesions 2 and 3 of AddInstance had 
  //the same parameters, we introduce the parameter "aux" in the third
  //version of AddInstance so the compiler can differentiate between
  //them)
  void AddInstance(char * iid, char * tid, char * name);
  void AddInstance(char * iid, char * tid);
  void AddInstance(char * iid, char * name, int aux);
  void AddInstance(char * iid);*/

private:

  char * iid;
  std::map<char *,ASTintances> instances;
};
