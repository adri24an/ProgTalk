#include "LatexPrint.h"

LatexPrint::LatexPrint() {
  decl = 0; // Al principio estamos declarando instancias.
  ofstream fs("communication.tex");
  msg = new string;
  pair<int,int> aux (-1,-1); // Inicializamos variable a valores te tiempo 
                             // imposibles.
  
  fs << "\\documentclass{article}\n";
  fs << "\\usepackage[a5paper,vmargin=1cm,hmargin=1cm]{geometry}\n";
  fs << "\\usepackage{msc}\n";
  fs << "\\begin{document}\n";
  fs << "\\thispagestyle{empty}\n\n";
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
  std::stringstream stream;

  if (decl == 0)
    {
      fs.open("communication.tex", fstream::app);
      fs << "\\declinst{" << i->get_iid() << "}{" << i->get_tid()
	 << "}{" << i->get_name() << "}\n";
      fs.close();
    }
  else
    {
      stream << "{" << i->get_iid() << "}";
      msg->append(stream.str());
    }
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
  if (decl != 1)
    decl = 1; // Esto no es muy elegante,
              // repetimos la operacion innecesariamente.
  if (aux.first == -1)
    aux.first = a->getAbsoluteTime();
  else
    aux.second = a->getAbsoluteTime();
}

void LatexPrint::visitRelative(Relative * r)
{
  if (decl != 1)
    decl = 1; // Esto no es muy elegante,
              // repetimos la operacion innecesariamente.
  if (aux.first == -1)
    aux.first = r->getAbsoluteTime();
  else
    aux.second = r->getAbsoluteTime();
}
