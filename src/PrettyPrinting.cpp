#include "PrettyPrinting.h"

PrettyPrinting::PrettyPrinting() {
}

PrettyPrinting::~PrettyPrinting() {
}

void PrettyPrinting::visitMSC(MSC * m)
{
  std::cout << "We are going to Pretty Printing the comunication that we "
	    << "parsed and storaged:" << std::endl << std::endl;
}

void PrettyPrinting::visitInstance(Instance * i)
{
  std::cout << "Instance -> IID: " << i->get_iid() <<
    " TID: " << i->get_tid() << " NAME: " << i->get_name() << std::endl;
}

void PrettyPrinting::visitMessage(Message * m)
{
  std::cout  << "Message -> MID: " << m->get_mid() <<
    " SMS: " << m->get_sms() << std::endl;
}

void PrettyPrinting::visitSending(Sending * s)
{
  std::cout << "Sending -> ";
}

void PrettyPrinting::visitReceipt(Receipt * r)
{
  std::cout << "Receipt -> ";
}

void PrettyPrinting::visitAbsolute(Absolute * a)
{
  std::cout << a->getAbsoluteTime() << "(Absolute)" << std::endl;
}

void PrettyPrinting::visitRelative(Relative * r)
{
  std::cout << r->getAbsoluteTime() << "(Relative)" << std::endl;
}
