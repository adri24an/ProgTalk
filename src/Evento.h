#include "Nodo.h"

class Evento
{
  Nodo nodo;
  Nodo *sig;
  
public:

  Evento();
  
  void AgregarNodo (Nodo nodo);
};
