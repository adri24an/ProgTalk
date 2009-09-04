#include "ListaEventos.h"

#include <string.h>

//------------------------------------------------------------------
// Clase NodoListaEventos
//------------------------------------------------------------------

//Construcutor de nodo lista eventos
NodoListaEventos :: NodoListaEventos (Evento * e)
{
	evento = e;
	sig = NULL;
}

//Destructor de nodo lista sitios
NodoListaEventos :: ~NodoListaEventos ()
{
	delete evento;
}

//Funcion que devuelve un puntero al siguiente nodo
NodoListaEventos * NodoListaEventos :: GetSig () const
{
	return sig;
}

//Funcion que coloca el puntero en el siguiente nodo
void NodoListaEventos :: SetSig (NodoListaEventos * nodo)
{
	sig = nodo;
}

//Funcion que devuelve la informacion de la pagina
//correspondiente al nodo.
Evento * NodoListaEventos :: GetEvento () const
{
	return evento;
}

//------------------------------------------------------------------
// Clase ListaEventos
//------------------------------------------------------------------

// Constructor de lista de eventos
ListaEventos :: ListaEventos()
{
	lista = NULL;
}

// Destructor de lista de eventos
ListaEventos :: ~ListaEventos()
{
	NodoListaEventos *ant, *act;
    act = lista;
    while (act)
    {
        ant = act;
        act = act->GetSig();
        delete ant;
    }
}

//Añadir un evento
void ListaEventos :: AnadirEvento (char * n1, int t1, char * n2, int t2, 
				   char * texto)
{
  NodoListaEventos * indice = lista;
  Evento * e;
  NodoListaEventos * n;

  while (indice->GetSig() != NULL)
    {
      indice->SetSig(indice->GetSig());
    }
 
  e = new Evento (n1, t1, n2, t2, texto);
  n = new NodoListaEventos (e);
  indice->SetSig(n);
}

