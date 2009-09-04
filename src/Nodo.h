struct tentidad
{
  char * nombre;
  int tiempo;
};

class Nodo
{
  struct tentidad entidad1;
  struct tentidad entidad2;
  char * texto;
    
public:

  Nodo(tentidad ent1, tentidad ent2, char * texto);

  char * GetEntidad1Nombre () const;
  int GetEntidad1Tiempo () const;
  char * GetEntidad2Nombre () const;
  int GetEntidad2Tiempo () const;
  char * GetTexto () const;
};
