#ifndef _PARSERVISITOR_H
#define _PARSERVISITOR_H

class Parser;
class MSC;
class Instance;
class Message;
class Sending;
class Receipt;
class Relative;
class Absolute;

class ParserVisitor {

 public:
  ParserVisitor();
  ~ParserVisitor();
  virtual void visitParser(Parser * p) = 0;
  virtual void visitMSC(MSC * m) = 0;
  virtual void visitInstance(Instance * i) = 0;
  virtual void visitMessage(Message * m) = 0;
  virtual void visitSending(Sending * s) = 0;
  virtual void visitReceipt(Receipt * r) = 0;
  virtual void visitAbsolute(Absolute * a) = 0;
  virtual void visitRelative(Relative * r) = 0;
};
#endif
