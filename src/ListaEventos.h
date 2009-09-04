#include "Evento.h"

class Evento
{
  Evento * nodo;
  Evento * sig;
  
public:

  ListaEventos(Evento e);
  
  void AgregarEvento (Evento e);
};



class CNodoListaPaginas
{
public:

	Evento(Nodo nodo);
	
	~Evento();
	
	//Funcion que devuelve un puntero al siguiente nodo
	CNodoListaPaginas * GetSig() const;
	
	//Funcion que coloca el puntero en el siguiente nodo
	void SetSig (CNodoListaPaginas * pagina);
	
	//Funcion que devuelve la informacion de la pagina
	//correspondiente al nodo.
	CPagina * GetPagina () const;

private:

	CPagina * pagina;
	CNodoListaPaginas * sig;
};

//-----------------------------------------------------------------
//Clase que representa la lista de paginas
//-----------------------------------------------------------------

class CListaPaginas
{
public:

	// Constructor de lista de paginas
	CListaPaginas();

	// Destructor de lista de paginas
	~CListaPaginas();

	//Dado un idp, devuelve un puntero a la pagina correspondiente
	CNodoListaPaginas * BuscarPagina (char * idp) const;

	//Alta de una pagina web
	void AltaPagina (ofstream &salida, char * ns, char * idp, char * url);

private:

	CNodoListaPaginas * lista;

};
