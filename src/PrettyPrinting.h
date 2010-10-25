#ifndef _PRETTYPRINTING_H
#define _PRETTYPRINTING_H

#include "Absolute.h"
#include "Relative.h"
#include "Sending.h"
#include "Instance.h"
#include "Message.h"
#include "MSC.h"
#include "ParserVisitor.h"
#include <iostream>

class PrettyPrinting : public ParserVisitor {

 public:
  PrettyPrinting();
  ~PrettyPrinting();
  void visitParser(Parser * p);
  void visitMSC(MSC * m);
  void visitInstance(Instance * i);
  void visitMessage(Message * m);
  void visitSending(Sending * s);
  void visitReceipt(Receipt * r);
  void visitAbsolute(Absolute * a);
  void visitRelative(Relative * r);
};
#endif
