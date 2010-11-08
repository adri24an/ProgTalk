#include "LatexPrint.h"

LatexPrint::LatexPrint() {
  ofstream fs("communication.msc");
  msg = new string;
  pair<int,int> aux (-1,-1);
  
  fs << "\\documentclass{article}\n";
  fs << "\\usepackage{msc}\n";
  fs << "\\begin{document}\n\n";
  fs << "\\begin{msc}{Communication}\n\n";
  fs.close();
}

LatexPrint::~LatexPrint() {
  delete msg;
}

void LatexPrint::visitMSC(MSC * m)
{
}

void LatexPrint::visitInstance(Instance * i)
{
  fs.open("communication.msc", fstream::app);
  fs << "\\declinst{" << i->get_iid() << "}{" << i->get_tid()
     << "}{" << i->get_name() << "}\n";
  fs.close();
}

void LatexPrint::visitInstanceEvent(Instance * i)
{
  std::stringstream stream;

  stream << "{" << i->get_iid() << "}";
  msg->append(stream.str());
}

void LatexPrint::visitMessage(Message * m)
{
  fs.open("communication.msc");
  fs << "\\mess{" << m->get_sms() << "}" << *msg;
  fs << "\\mscmark{t=" << aux.first << "}{" 
     << m->get_sending()->get_instance() << "}\n";
  fs << "\\nextlevel\n";
  fs << "\\mscmark{t=" << aux.second << "}{" 
     << m->get_receipt()->get_instance() << "}\n";
}

void LatexPrint::visitSending(Sending * s)
{
}

void LatexPrint::visitReceipt(Receipt * r)
{
}

void LatexPrint::visitAbsolute(Absolute * a)
{
  if (aux.first == -1)
    aux.first = a->getAbsoluteTime();
  else
    aux.second = a->getAbsoluteTime();
}

void LatexPrint::visitRelative(Relative * r)
{
  if (aux.first == -1)
    aux.first = r->getAbsoluteTime();
  else
    aux.second = r->getAbsoluteTime();
}
