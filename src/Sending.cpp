
#include "Sending.h"
#include "Instance.h"
#include "Timestamp.h"

Sending::Sending( Instance & new_inst, Timestamp & new_time) {
  inst = &new_inst;
  time = &new_time;
}

Sending::~Sending() {
}

string Sending::getInstance() {
  return inst->get_iid();
}

int Sending::getTime() {
  return time->getAbsoluteTime();
}

void Sending::print() {
  std::cout << "instancia:" << std::endl;
  inst->print();
  std::cout << "timestamp:" << std::endl;
  time->print();
}

void Sending::accept(MSCVisitor & visitor) {
  inst->accept(visitor);
  time->accept(visitor);
  visitor.visitSending(this);
}

