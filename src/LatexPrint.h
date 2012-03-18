#ifndef _LATEXPRINT_H
#define _LATEXPRINT_H

#include "Absolute.h"
#include "Relative.h"
#include "Sending.h"
#include "Instance.h"
#include "Message.h"
#include "MSC.h"
#include "MSCVisitor.h"
#include <iostream>
#include <string>
#include <fstream>

class LatexPrint : public MSCVisitor {

 public:

  LatexPrint();
  ~LatexPrint();
  void visitMSC(MSC * m);
  void visitInstance(Instance * i);
  void visitMessage(Message * m);
  void visitSending(Sending * s);
  void visitReceipt(Receipt * r);
  void visitAbsolute(Absolute * a);
  void visitRelative(Relative * r);

 private:
  
  ofstream fs; // Fichero sobre el que generamos la comnicacion traducida.
  string * msg; // Variable temporal donde almacenamos sentencias.
  pair<int,int> aux; // Variable temporal donde almacenamos tiempos de envio y 
                     // recepción de un mensaje.
  int decl; // Variable que nos dice si estamos declarando instancias (0) o
            // si por el contrario estamos en la zona de mensajes (1).
};
#endif 
