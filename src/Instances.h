#include "string.h"

class Instances
{
  
public:

  Instances();
  ~Instances();

  Instances * getInstances();
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
  void AddInstance(std::string iid, std::string tid, std::string name);
  void AddInstance(std::string iid, std::string tid);
  void AddInstance(std::string iid, std::string name, int aux);
  void AddInstance(std::string iid);

private:

  char * iid;
  char * tid;
  char * name;
};
