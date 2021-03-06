#ifndef _PRETTYPRINTING_H
#define _PRETTYPRINTING_H

#include "Absolute.h"
#include "Relative.h"
#include "Sending.h"
#include "Instance.h"
#include "Message.h"
#include "MSC.h"
#include "MSCVisitor.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

class PrettyPrinting : public MSCVisitor {

 public:

  PrettyPrinting();
  ~PrettyPrinting();
  void visitMSC(MSC * m);
  void visitInstance(Instance * i);
  void visitMessage(Message * m);
  void visitSending(Sending * s);
  void visitReceipt(Receipt * r);
  void visitAbsolute(Absolute * a);
  void visitRelative(Relative * r);

 private:
  
  /*//Variable where we will storage instances' info prior to print it.
  list<string> instancesList;
  //Variable where we will storage messages' info prior to print it.
  list<vector<string> > messagesList;*/

  vector<string> * element;

};
#endif
