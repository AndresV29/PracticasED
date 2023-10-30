//Practica en clase 3
//Gestor de Llamadas
//Andres Villalobos Carballo 1-1886-0295
#include <iostream>
#include "PilaLlamadas.h"
using namespace std;

PilaLlamadas miPila;

void capturaDatos(){
    string nombre, estado;
    int numero = 0;
    Llamada nueva(numero, nombre);
    cout<< "Ingrese el numero: ";
    cin >> numero;
    cout<< "Ingrese el nombre: ";
    cin >> nombre;
    miPila.registraLlamada(nueva);
    cout << "Llamada registrada con exito!" << endl;
}


void menu(){
    int opcion;
    do {
        cout << "Main Menu" << endl;
        cout << "1. Registrar llamada" << endl;
        cout << "2. Atender ultima llamada" << endl;
        cout << "3. Mostrar ultima llamada" << endl;
        cout << "4. Mostrar registro de Llamadas" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "You selected Option 1" << endl;
                capturaDatos();
                break;
            case 2:
                miPila.atenderUltimaLlamada();
                break;
            case 3:
                miPila.mostrarUltimaLlamada();
                break;
            case 4:
                miPila.mostrarTodo();
                break;
            case 5:
                cout << "Tenga buen dia";
                break;
            default:
                cout << "Opcion invalida" << endl;
                return;
        }
    } while (true);
}
int main(){
    menu();
    return 0;
}
