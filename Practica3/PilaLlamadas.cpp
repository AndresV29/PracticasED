//
// Created by andre on 10/24/2023.
//

#include "PilaLlamadas.h"

PilaLlamadas::PilaLlamadas() {
    laPila = new stack<Llamada>;
}

void PilaLlamadas::registraLlamada(Llamada llamada){
    laPila->push(llamada);
}
Llamada PilaLlamadas::atenderUltimaLlamada(){
    Llamada temp = laPila->top();
    laPila->pop();
    return temp;
}
Llamada PilaLlamadas::mostrarUltimaLlamada(){
    return laPila->top();
}
string PilaLlamadas::mostrarTodo(){
    stringstream ss;
    stack<Llamada> temp;
    Llamada valorPivote;
    int tam = laPila->size();
    for(int i = 0; i < tam; i++){
        valorPivote = atenderUltimaLlamada();
        ss << valorPivote << endl;
        temp.push(valorPivote);
    }
    tam = temp.size();
    for(int i = 0; i < tam; i++){
        valorPivote = temp.top();
        temp.pop();
        laPila->push(valorPivote);
    }
    return ss.str();
}
