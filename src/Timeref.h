#ifndef Timeref_h_included
#define Timeref_h_included


class Timeref
{
  
public:

  Timeref(int new_valtype, int new_value);
  ~Timeref ();

  //Returns the type of time storaged (absolute, relative to a specific message,
  //or relative without an specific message)
  int getValtype ();
  //Returns event's time
  int getValue ();
  //Sets Valtype value
  void setValtype (int new_valtype);
  //Sets Value value
  void setValue (int new_value);

private:

  int valtype; // 0 = defined abs or rel, 1 = undefined rel, 2 = @+1
  int value;
};

#endif
