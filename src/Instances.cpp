#include "Instances.h"

Instances :: Instances()
  :astInst()
{
}

Instances :: ~Instances()
{
}

void Instances :: addInst(char * new_iid, char * new_tid, char * new_name)
{ 
    ASTinstances * i;

    std::cout << "entra en instances.addInst" << std::endl;
    if(astInst.find(new_iid) == astInst.end())
      {
	i = new ASTinstances(new_tid, new_name);
	astInst[new_iid] = i;
      }
    else
      {
	std::cout << "Error: The instance already exists." << std::endl;
      }
}
