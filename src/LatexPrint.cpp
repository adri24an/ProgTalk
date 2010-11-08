#include "LatexPrint.h"

LatexPrint::LatexPrint() {
  ofstream fs("communication.msc");
  
  fs << "\\documentclass{article}\n";
  fs << "\\usepackage{msc}\n";
  fs << "\\begin{document}\n\n";
  fs << "\\begin{msc}{Communication}\n\n";
  fs.close();
}

LatexPrint::~LatexPrint() {
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
}

void LatexPrint::visitMessage(Message * m)
{
}

void LatexPrint::visitSending(Sending * s)
{
}

void LatexPrint::visitReceipt(Receipt * r)
{
}

void LatexPrint::visitAbsolute(Absolute * a)
{
}

void LatexPrint::visitRelative(Relative * r)
{
}
