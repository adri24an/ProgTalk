#include "Evento.h"

#include <string.h>

Evento :: Evento (char * n1, int t1, char * n2, int t2, char * texto)
{
  this -> entidad1.nombre = new char[strlen(n1)+1];
  strcpy (this -> entidad1.nombre, n1);
  this -> entidad1.tiempo = t1;
  this -> entidad2.nombre = new char[strlen(n2)+1];
  strcpy (this -> entidad2.nombre, n2);
  this -> entidad2.tiempo = t2;
  this -> texto = new char[strlen(texto)+1];
  strcpy (this -> texto, texto);
}

Evento :: ~Evento()
{
  delete entidad1.nombre;
  delete entidad2.nombre;
  delete texto;
}

char * Evento :: GetEntidad1Nombre () const
{
  return this -> entidad1.nombre;
}

int Evento :: GetEntidad1Tiempo () const
{
  return this -> entidad1.tiempo;
}

char * Evento :: GetEntidad2Nombre () const
{
  return this -> entidad2.nombre;
}

int Evento :: GetEntidad2Tiempo () const
{
  return this -> entidad2.tiempo;
}

char * Evento :: GetTexto () const
{
  return this -> texto;
}
