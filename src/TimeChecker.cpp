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

void TimeChecker::visitMessage(Message * m) {
}

void TimeChecker::visitSending(Sending * s) {
}

void TimeChecker::visitReceipt(Receipt * r) {
}

void TimeChecker::visitAbsolute(Absolute * a) {
  int time = a->getAbsoluteTime();
  
  if (limit == -1) //If it's a sending time
    {
      if (time < 0)
	{
	  std::cout << "Error: an event's time can't be less than zero."
		    << std::endl;
	  exit(-1);
	}
      else
	{
	  limit = time;
	}
    }
  else
    {
      if (time < 0) //If it's a reception time
	{
	  std::cout << "Error: an event's time can't be less than zero."
		    << std::endl;
	  exit(-1);
	}
      else if (time <= limit)
	{
	  std::cout << "Error: a message can't be received before it was sent."
		    << std::endl;
	  exit(-1);
	}
      limit = -1; //We reset limit to check the next message interchange
    }
  
}

void TimeChecker::visitRelative(Relative * r) {
  int time = r->getAbsoluteTime();
  
  if (limit == -1)
    {
      if (time < 0)
	{
	  std::cout << "Error: an event's time can't be less than zero."
		    << std::endl;
	  exit(-1);
	}
      else
	{
	  limit = time;
	}
    }
  else
    {
      if (time < 0)
	{
	  std::cout << "Error: an event's time can't be less than zero."
		    << std::endl;
	  exit(-1);
	}
      else if (time <= limit)
	{
	  std::cout << "Error: a message can't be received before it was sent."
		    << std::endl;
	  exit(-1);
	}
      limit = -1; //We reset limit to check the next message interchange
    }
}
