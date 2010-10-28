#include "PrettyPrinting.h"

PrettyPrinting::PrettyPrinting() {
  msg = new string();
}

PrettyPrinting::~PrettyPrinting() {
}

void PrettyPrinting::visitMSC(MSC * m)
{
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Fin de la comunicacion" << std::endl << std::endl;
}

void PrettyPrinting::visitInstance(Instance * i)
{
  std::cout << i->get_iid() << " " << i->get_tid() 
	    << " " << i->get_name() << std::endl;
}

void PrettyPrinting::visitInstanceEvent(Instance * i)
{
  std::stringstream stream;
  
  stream << i->get_iid() << " " 
	 << i->get_tid() << " " << i->get_name() << std::endl;
 
  *msg = *msg + stream.str();
}

void PrettyPrinting::visitMessage(Message * m)
{
  std::stringstream stream;
  string tid = m->get_mid();
  string sms = m->get_sms();

  stream << std::endl;
  *msg = stream.str() + tid + " " + sms + stream.str() + *msg;
  std::cout << *msg;
  delete msg;
  msg = new string();
}

void PrettyPrinting::visitSending(Sending * s)
{
  *msg = *msg;
}

void PrettyPrinting::visitReceipt(Receipt * r)
{
  *msg = *msg;
}

void PrettyPrinting::visitAbsolute(Absolute * a)
{
  std::stringstream stream;

  stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
  msg->append(stream.str());
}

void PrettyPrinting::visitRelative(Relative * r)
{
  std::stringstream stream;

  stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
  msg->append(stream.str());
}
