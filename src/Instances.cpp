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
  std::map<char *, ASTinstances *>::const_iterator
    mit (astInst.begin()),
    mend(astInst.end());

  for(;mit!=mend;++mit) 
	{
	  if (!(strcmp(mit->first, new_iid)))
		{	
		  std::cout << "Error: The instance already exists." << std::endl;
		  exit(0); 
		}
	}
  
  i = new ASTinstances(new_tid, new_name);
  astInst[new_iid] = i;
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
