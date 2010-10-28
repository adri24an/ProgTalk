#ifndef _MSCVISITOR_H
#define _MSCVISITOR_H

class Parser;
class MSC;
class Instance;
class Message;
class Sending;
class Receipt;
class Relative;
class Absolute;

class MSCVisitor {

 public:
  MSCVisitor();
  ~MSCVisitor();
  virtual void visitMSC(MSC * m) = 0;
  virtual void visitInstance(Instance * i) = 0;
  virtual void visitMessage(Message * m) = 0;
  virtual void visitSending(Sending * s) = 0;
  virtual void visitReceipt(Receipt * r) = 0;
  virtual void visitAbsolute(Absolute * a) = 0;
  virtual void visitRelative(Relative * r) = 0;
};
#endif
