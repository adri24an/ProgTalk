//#include "Parser.h"
#include "Instance.h"
#include "MSC.h"

int main()
{
  //Parser * parser = new Parser;

  //parser->parse();

  Instance i ("sms1", "type1", "comment");
  MSC * msc = new MSC;
  msc->addInst(i);
  msc->print();
  
  return 0;
}
