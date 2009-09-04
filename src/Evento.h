struct tentidad
{
  char * nombre;
  int tiempo;
};

class Evento
{
  struct tentidad entidad1;
  struct tentidad entidad2;
  char * texto;
    
public:

  Evento(char * n1, int t1, char * n2, int t2, char * texto);

  char * GetEntidad1Nombre () const;
  int GetEntidad1Tiempo () const;
  char * GetEntidad2Nombre () const;
  int GetEntidad2Tiempo () const;
  char * GetTexto () const;
};
