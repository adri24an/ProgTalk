#include "LatexPrint.h"

LatexPrint::LatexPrint() {
  ofstream * fs = new fs("communication.msc");
  fs << "\documentclass{article}" << std::endl 
     << "\usepackage{msc}" << std::endl
     << "\begin{document}" << std::endl << std::endl
     << "\begin{msc}{Communication}" << std::endl << std::endl;
}

LatexPrint::~LatexPrint() {
  fs.close();
}

void LatexPrint::visitMSC(MSC * m)
{
}

void LatexPrint::visitInstance(Instance * i)
{
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
