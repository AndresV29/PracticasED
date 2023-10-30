//
// Created by andre on 10/24/2023.
//
#include <iostream>
#include <stack>
#include "Llamada.h"

Llamada::Llamada(int numero, const string &nombre) : numero(numero), nombre(nombre)
                                                                            {}

int Llamada::getNumero() const {
    return numero;
}

void Llamada::setNumero(int numero) {
    Llamada::numero = numero;
}

const string &Llamada::getNombre() const {
    return nombre;
}

void Llamada::setNombre(const string &nombre) {
    Llamada::nombre = nombre;
}

// const string &Llamada::getEstado() const {
//     return estado;
// }

// void Llamada::setEstado(const string &estado) {
//     Llamada::estado = estado;
// }

Llamada::Llamada() {}

ostream &operator<<(ostream &os, const Llamada &llamada) {
    os << "numero: " << llamada.numero << " nombre: " << llamada.nombre << endl;
    return os;
}
