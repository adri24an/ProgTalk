#ifndef _LATEXPRINT_H
#define _LATEXPRINT_H

#include "Absolute.h"
#include "Relative.h"
#include "Sending.h"
#include "Instance.h"
#include "Message.h"
#include "MSC.h"
#include "MSCVisitor.h"
#include <iostream>
#include <string>
#include <fstream>

class LatexPrint : public MSCVisitor {

 public:

  LatexPrint();
  ~LatexPrint();
  void visitMSC(MSC * m);
  void visitInstance(Instance * i);
  void visitInstanceEvent(Instance * i);
  void visitMessage(Message * m);
  void visitSending(Sending * s);
  void visitReceipt(Receipt * r);
  void visitAbsolute(Absolute * a);
  void visitRelative(Relative * r);

 private:
  
  ofstream fs;
};
#endif 
