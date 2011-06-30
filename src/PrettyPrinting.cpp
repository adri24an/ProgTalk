#include "PrettyPrinting.h"

PrettyPrinting::PrettyPrinting()
  :instancesList(), messagesList()
{
  element = NULL;
  /*msg = new string();*/
}

PrettyPrinting::~PrettyPrinting() 
{
  delete instancesList;
  delete messagesList;
  /*delete msg;*/
}

void PrettyPrinting::visitMSC(MSC * m)
{
  /*std::cout << "----------------------------------------" << std::endl;
  std::cout << "Fin de la comunicacion" << std::endl << std::endl;*/
}

void PrettyPrinting::visitInstance(Instance * i)
{
  std::stringstream stream;
  
  // Si no existe element, es que estamos declarando instancias
  if (element == NULL)
    {
      stream << i->get_iid() << " " 
	     << i->get_tid() << " " << i->get_name() << std::endl;
      instancesList->push_back(stream.str());
    }
  // Si existe es que estamos hablando de referencias a instancias.
  else 
    {
      if ((*element)[4].compare("_NULL_") == 0)
	(*element)[4] = i->get_iid();

      else
	(*element)[2] = i->get_iid();
    }


  /*std::cout << i->get_iid() << " " << i->get_tid() 
	    << " " << i->get_name() << std::endl;*/
}

void PrettyPrinting::visitMessage(Message * m)
{
  
  /*std::stringstream stream;
  string tid = m->get_mid();
  string sms = m->get_sms();

  stream << std::endl;
  *msg = stream.str() + tid + " " + sms + stream.str() + *msg;
  std::cout << *msg;
  delete msg;
  msg = new string();*/
}

void PrettyPrinting::visitSending(Sending * s)
{
  ;
  /**msg = *msg;*/
}

void PrettyPrinting::visitReceipt(Receipt * r)
{
  ;
  /**msg = *msg;*/
}

void PrettyPrinting::visitAbsolute(Absolute * a)
{
  std::stringstream stream;
  
  // Si es el tiempo de recepción (el 1º de los tiempos que leemos)
  // creamos el vector luego lo rellenamos con dicoh tiempo de recepción.
  if (element == NULL)
    {
      element = new vector<string>(6,"_NULL_");
      stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
      (*element)[5] = stream.str();
    }
  // Si es el tiempo de envío (el 2º que leemos) lo guardamos en su sitio
  // en el vector.
  else
    {
      stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
      (*element)[3] = stream.str();
    }

  /*std::stringstream stream;

  stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
  msg->append(stream.str());*/
}

void PrettyPrinting::visitRelative(Relative * r)
{
  std::stringstream stream;
  
  // Si es el tiempo de recepción (el 1º de los tiempos que leemos)
  // creamos el vector luego lo rellenamos con dicoh tiempo de recepción.
  if (element == NULL)
    {
      element = new vector<string>(6,"_NULL_");
      stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
      (*element)[5] = stream.str();
    }
  // Si es el tiempo de envío (el 2º que leemos) lo guardamos en su sitio
  // en el vector.
  else
    {
      stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
      (*element)[3] = stream.str();
    }

  /*std::stringstream stream;

  stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
  msg->append(stream.str());*/
}
