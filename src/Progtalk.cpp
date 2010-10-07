//#include "Parser.h"
#include "Instance.h"
#include "MSC.h"

int main()
{
  //Parser * parser = new Parser;

  //parser->parse();

  Instance i1 ("sms1", "type1", "comment");
  Instance i2 ("sms2", "type2", "comment number two");
  Instance i3 ("sms3", "type3", "comment number three");
  Message m1();
  MSC * msc = new MSC;

  msc->addInst(i1);
  msc->addInst(i2);
  msc->addInst(i3);
  msc->print();
  
  return 0;
}
