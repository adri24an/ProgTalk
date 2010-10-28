#include "TimeChecker.h"

TimeChecker::TimeChecker() {
  limit = -1;
}

TimeChecker::~TimeChecker() {
}

void TimeChecker::visitMSC(MSC * m) {
}

void TimeChecker::visitInstance(Instance * i) {
}

void TimeChecker::visitInstanceEvent(Instance * i) {
}

void TimeChecker::visitMessage(Message * m) {
}

void TimeChecker::visitSending(Sending * s) {
}

void TimeChecker::visitReceipt(Receipt * r) {
}

void TimeChecker::visitAbsolute(Absolute * a) {
  int time = a->getAbsoluteTime();
  
  if ((time < 0) || (time <= limit))
    {
      std::cout << "Error: the timing in the communication is incorrect";
      exit(-1);
    }
  else
    {
      limit = time;
    }
}

void TimeChecker::visitRelative(Relative * r) {
  int time = r->getAbsoluteTime();
  
  if ((time < 0) || (time <= limit))
    {
      std::cout << "Error: the timing in the communication isn't correct."
		<< std::endl << "The time: " << time 
		<< " is minor or equal than " << limit << std::endl;
      exit(-1);
    }
  else
    {
      limit = time;
    }
}
