#include "Evento.h"

class Evento
{
  Evento * nodo;
  Evento * sig;
  
public:

  ListaEventos(Evento e);
  
  void AgregarEvento (Evento e);
};

----------------------------------

class NodoListaEventos
{
public:

	NodoListaEventos(Evento evento);
	
	~NodoListaEventos();
	
	//Funcion que devuelve un puntero al siguiente nodo
	NodoListaEventos * GetSig() const;
	
	//Funcion que coloca el puntero en el siguiente nodo
	void SetSig (NodoListaEventos * evento);
	
	//Funcion que devuelve la informacion del evento
	//correspondiente al nodo.
	Evento * GetEvento () const;

private:

	Evento * evento;
        NodoListaEventos * sig;
};

//-----------------------------------------------------------------
//Clase que representa la lista de paginas
//-----------------------------------------------------------------

class ListaEventos
{
public:

	// Constructor de lista de eventos
	ListaEventos();

	// Destructor de lista de eventos
	~ListaEventos();

	// Añade un evento
	void AñadirEvento (char * n1, int t1, char * n2, int t2, char * texto);

private:

	NodoListaEventos * lista;

};
