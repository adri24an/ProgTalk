//#include "Parser.h"
#include "Absolute.h"
#include "Relative.h"
#include "Sending.h"
#include "Receipt.h"
#include "Instance.h"
#include "Message.h"
#include "MSC.h"

int main()
{
  //Parser * parser = new Parser;

  //parser->parse();

  Instance i1 ("id1", "type1", "comment");
  Instance i2 ("id2", "type2", "comment number two");
  Instance i3 ("id3", "type3", "comment number three");

  Absolute a1 (1);
  Sending s1 (i1, a1);

  Relative re1 (2, s1);
  Receipt r1 (i2, re1);

  Message m1("m1", "sms1", s1, r1);

  MSC * msc = new MSC;

  msc->addInst(i1);
  msc->addInst(i2);
  msc->addInst(i3);
  msc->addMsg(m1);
  msc->print();
  
  return 0;
}
