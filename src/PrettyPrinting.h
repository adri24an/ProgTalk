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
  
  string * msg;
  /* Atributo para recordar la última instancia visitada */
  //Instance *lastVisitedInstance;

};
#endif
