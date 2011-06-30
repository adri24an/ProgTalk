
#include "Receipt.h"
#include "Instance.h"
#include "Timestamp.h"

Receipt::Receipt(Instance & new_inst, Timestamp & new_time) {
  inst = &new_inst;
  time = &new_time;
}

Receipt::~Receipt() {
}

string Receipt::getInstance() {
  return inst->get_iid();
}

int Receipt::getTime() {
  return time->getAbsoluteTime();
}

void Receipt::print() {
  std::cout << "instancia:" << std::endl;
  inst->print();
  std::cout << "timestamp:" << std::endl;
  time->print();
}

void Receipt::accept(MSCVisitor & visitor) {
  inst->accept(visitor);
  time->accept(visitor);
  visitor.visitReceipt(this);
    
}

