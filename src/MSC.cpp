#include "MSC.h"

MSC :: MSC()
{
  instances = new Instances;
  messages = new Messages;
}

void MSC :: addInst (char * new_iid, char * new_tid, char * new_name)
{
  instances->addInst (new_iid, new_tid, new_name);
}

void MSC :: addMsg (char * new_mid, char * new_sms, char * new_origin,
char * new_destiny, int new_time_sent, int new_time_rec)
{
  messages->addMsg (new_mid, new_sms, new_origin, new_destiny,
new_time_sent, new_time_rec);
}
int MSC :: getTime_sent(char * mid)
{
  int time = messages->getTime_sent(mid);

  return time;
}

int MSC :: getTime_rec(char * mid)
{
  int time = messages->getTime_rec(mid);

  return time;
}

int MSC :: getTime_sent(int id)
{
  int time = messages->getTime_sent(id);

  return time;
}

int MSC :: getTime_rec(int id)
{
  int time = messages->getTime_rec(id);

  return time;
}

int MSC :: msgSize()
{
  return messages->msgSize();
}

void MSC :: myPrint()
{
  std::cout << "Las instancias son:" << std::endl;
  instances->myPrint();
  std::cout << "Los mensajes son:" << std::endl;
  messages->myPrint();
  std::cout << "Fin de la impresion" << std::endl;
}
