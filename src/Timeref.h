#ifndef Timeref_h_included
#define Timeref_h_included


class Timeref
{
  
public:

  Timeref(int new_valtype, int new_value);
  ~Timeref ();
  int getValtype ();
  int getValue ();
  void setValtype (int new_valtype);
  void setValue (int new_value);

private:

  int valtype; // 0 = defined abs or rel, 1 = undefined rel, 2 = @+1
  int value;
};

#endif
