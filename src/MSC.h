#include "Instances.h"
#include "Messages.h"

class MSC
{
  
public:

  MSC();
  ~MSC();
  MSC getMSC ();

private:

  Instances * instances;
  Messages * messages;
};
