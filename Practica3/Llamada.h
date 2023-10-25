//
// Created by andre on 10/24/2023.
//

#ifndef PRACTICA3_LLAMADA_H
#define PRACTICA3_LLAMADA_H
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Llamada {
private:
    int numero;
    string nombre, estado;
public:
    Llamada();

    Llamada(int numero, const string &nombre, const string &estado);
    int getNumero() const;
    void setNumero(int numero);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getEstado() const;
    void setEstado(const string &estado);

    friend ostream &operator<<(ostream &os, const Llamada &llamada);
};


#endif //PRACTICA3_LLAMADA_H
