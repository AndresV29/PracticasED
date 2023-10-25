//
// Created by andre on 10/24/2023.
//

#ifndef PRACTICA3_PILALLAMADAS_H
#define PRACTICA3_PILALLAMADAS_H

#include "Llamada.h"

class PilaLlamadas {
private:
    stack<Llamada> *laPila;
public:
    PilaLlamadas();
    void registraLlamada(Llamada llamada);
    Llamada atenderUltimaLlamada();
    Llamada mostrarUltimaLlamada();
    string mostrarTodo();

};


#endif //PRACTICA3_PILALLAMADAS_H
