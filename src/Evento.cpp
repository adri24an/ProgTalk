#include "Evento.h"

#include <string.h>

Evento :: Evento (tentidad ent1, tentidad ent2, char * texto)
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
