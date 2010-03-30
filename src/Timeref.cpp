#include "Timeref.h"

Timeref :: Timeref(int new_valtype, int new_value)
{
    valtype = new_valtype;
    value = new_value;
}

Timeref :: ~Timeref()
{
}

int Timeref :: getValtype ()
{
    return valtype;
}
int Timeref :: getValue ()
{
    return value;
}

void Timeref :: setValtype (int new_valtype)
{
    valtype = new_valtype;
}
void Timeref :: setValue (int new_value)
{
    value = new_value;
}
