#include "PrettyPrinting.h"

PrettyPrinting::PrettyPrinting()
//  :instancesList(), messagesList()
{
  element = NULL;
  /*msg = new string();*/
}

PrettyPrinting::~PrettyPrinting() 
{
  delete element;
  /*delete msg;*/
}

void PrettyPrinting::visitMSC(MSC * m)
{
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "Fin de la comunicacion" << std::endl << std::endl;
}

void PrettyPrinting::visitInstance(Instance * i)
{
  std::stringstream stream;
  
  // Si no existe element, es que estamos declarando instancias
  if (element == NULL)
    {
      stream << i->get_iid() << " " 
	     << i->get_tid() << " " << i->get_name() << std::endl;

      cout << stream.str();
      //instancesList.push_front(stream.str());
    }
  // Si existe es que estamos hablando de referencias a instancias.
  else 
    {
      //Si la posición 2 del vector es _NULL_ es que aún no se ha rellenado
      //por lo que la referencia a instancia es de envío.
      if (((*element)[2].compare("_NULL_")) == 0)
	(*element)[2] = i->get_iid();
      //Sino la referencia de instancia es de recepción.
      else
	(*element)[4] = i->get_iid();
    }


  /*std::cout << i->get_iid() << " " << i->get_tid() 
	    << " " << i->get_name() << std::endl;*/
}

void PrettyPrinting::visitMessage(Message * m)
{
  std::stringstream stream;
  int i = 0;
  
  (*element)[0] = m->get_mid();
  (*element)[1] = m->get_sms();
  
  for(i=0;i<6;i++)
    {
      cout << (*element)[i] << " "; 
    }
  
  cout << endl;
  delete element;
  element = NULL;

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
  
  // Si es el tiempo de envío (el 1º de los tiempos que leemos)
  // creamos el vector luego lo rellenamos con dicho tiempo de recepción.
  if (element == NULL)
    {
      element = new vector<string>(6,"_NULL_");
      stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
      (*element)[3] = stream.str();
    }
  // Si es el tiempo de recepción (el 2º que leemos) lo guardamos en su sitio
  // en el vector.
  else
    {
      stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
      (*element)[5] = stream.str();
    }

  /*std::stringstream stream;

  stream << a->getAbsoluteTime() << " (ABSOLUTE)" << std::endl;
  msg->append(stream.str());*/
}

void PrettyPrinting::visitRelative(Relative * r)
{
  std::stringstream stream;
  
  // Si es el tiempo de envío (el 1º de los tiempos que leemos)
  // creamos el vector luego lo rellenamos con dicho tiempo de recepción.
  if (element == NULL)
    {
      element = new vector<string>(6,"_NULL_");
      stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
      (*element)[3] = stream.str();
    }
  // Si es el tiempo de recepción (el 2º que leemos) lo guardamos en su sitio
  // en el vector.
  else
    {
      stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
      (*element)[5] = stream.str();
    }

  /*std::stringstream stream;

  stream << r->getAbsoluteTime() << " (RELATIVE)" << std::endl;
  msg->append(stream.str());*/
}
