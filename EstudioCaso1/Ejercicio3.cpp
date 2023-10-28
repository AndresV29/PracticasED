//
// Created by andre on 10/28/2023.
//Estacionamiento

#include "Ejer3.h"
#include <iostream>
#include <stack>
#include <limits>
#include <sstream>
using namespace std;
struct Auto {
    string modelo, placa;
};
stack<Auto> estacionamiento;

void agregaAuto(Auto nuevo){
    estacionamiento.push(nuevo);
    return;
}

void eliminaAuto(){
    estacionamiento.pop();
    cout << "Se ha eliminado un Auto del Estacionamiento" << endl;
    return;
}
stringstream mostrarAutos(){
    stringstream ss;
    stack<Auto> temp;
    Auto valorPivote;
    int tam = estacionamiento.size();
    cout << "Autos Estacionados"<< endl;
    for(int i = 0; i < tam; i++){
        valorPivote =  estacionamiento.top();
        ss << "Placa: " << valorPivote.placa << " Modelo: "<< valorPivote.modelo << endl;
        temp.push(valorPivote);
    }
    tam = temp.size();
    for(int i = 0; i < tam; i++){
        valorPivote = temp.top();
        temp.pop();
        estacionamiento.push(valorPivote);
    }
    return ss;
}

void menuEst(){
    int opcion;
    string modelo, placa;
    Auto nuevo;
    do {
        cout << "Estacionamiento" << endl;
        cout << "1. Agregar Auto" << endl;
        cout << "2. Eliminar Auto" << endl;
        cout << "3. Mostrar Autos" << endl;
        cout << "4. Buscar Auto." << endl;
        cout << "5. Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el modelo del auto: ";
                cin.clear();
                cin.ignore(1000000);
                getline(cin, nuevo.modelo);
                //cin >> nom;
                cout << "Ingrese la placa del vehiculo: ";
                cin >> nuevo.placa;
                agregaAuto(nuevo);
                break;
            case 2:
                eliminaAuto();
                break;
            case 3:
                mostrarContactos(inventario);
                break;
            case 4:
                cout << "Ingrese el nombre del contacto: ";
                cin >> nom;
                buscarContacto(inventario, nom);
                break;
            case 5:
                return;
            default:
                cout << "Seleccione una opcione valida";
                menuEst();
                break;
        }
    }while (true);
}

int main(){
    menuEst();
    return 0;
}