#include "LatexPrint.h"

LatexPrint::LatexPrint() {
  ofstream fs("communication.tex");
  msg = new string;
  pair<int,int> aux (-1,-1);
  
  fs << "\\documentclass{article}\n";
  fs << "\\usepackage{msc}\n";
  fs << "\\begin{document}\n\n";
  fs << "\\setlength{\\firstlevelheight}{1cm}\n\n";
  fs << "\\begin{msc}{Communication}\n\n";
  fs.close();
}

LatexPrint::~LatexPrint() {
  delete msg;
}

void LatexPrint::visitMSC(MSC * m)
{
  fs.open("communication.tex", fstream::app);
  fs << "\n\\end{msc}\n" << "\\end{document}";
  fs.close();
}

void LatexPrint::visitInstance(Instance * i)
{
  fs.open("communication.tex", fstream::app);
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
  fs.open("communication.tex", fstream::app);
  fs << "\n\\mess{" << m->get_sms() << "}" << *msg << "[3]\n";
  fs << "\\mscmark{t=" << aux.first << "}{" 
     << m->get_sending()->getInstance() << "}\n";
  fs << "\\nextlevel[3]\n";
  fs << "\\mscmark[br]{t=" << aux.second << "}{" 
     << m->get_receipt()->getInstance() << "}\n";
  fs << "\\nextlevel[3]\n";
  fs.close();
  delete msg;
  msg = new string();
  aux.first = -1;
  aux.second = -1;
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
