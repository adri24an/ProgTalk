#include "Nodo.h"

#include <string.h>

Nodo :: Nodo (tentidad ent1, tentidad ent2, char * texto)
{
  this -> entidad1.nombre = new char[strlen(ent1.nombre)+1];
  strcpy (this -> entidad1.nombre, ent1.nombre);
  this -> entidad1.tiempo = ent1.tiempo;
  this -> entidad2.nombre = new char[strlen(ent2.nombre)+1];
  strcpy (this -> entidad2.nombre, ent2.nombre);
  this -> entidad2.tiempo = ent2.tiempo;
  this -> texto = new char[strlen(texto)+1];
  strcpy (this -> texto, texto);
}

char * Nodo :: GetEntidad1Nombre () const
{
  return this -> entidad1.nombre;
}

int Nodo :: GetEntidad1Tiempo () const
{
  return this -> entidad1.tiempo;
}

char * Nodo :: GetEntidad2Nombre () const
{
  return this -> entidad2.nombre;
}

int Nodo :: GetEntidad2Tiempo () const
{
  return this -> entidad2.tiempo;
}

char * Nodo :: GetTexto () const
{
  return this -> texto;
}
