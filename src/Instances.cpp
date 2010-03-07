#include "Instances.h"

Instances :: Instances()
{
}

void Instances :: addInst(char * newiid, char * newtid, char * newname)
{
    ASTinstances * i = new ASTinstances(newtid, newname);
    astInst[newiid] = i;
}
