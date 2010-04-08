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

void Instances :: myPrint()
{
  std::map<char *, ASTinstances *>::const_iterator
    mit (astInst.begin()),
    mend(astInst.end());
  for(;mit!=mend;++mit) 
	{
	  std::cout << mit->first << " -> ";
	  mit->second->myPrint();
	}
}
