//
// Created by andre on 10/25/2023.
//Almacen de productos
#include <iostream>
#include <vector>
#include <list>
#include "Ejer1.h"
using namespace std;

struct Nodo{
    Nodo* sig;
    string nombreProducto, cantidad;
};
void agregarProd(Nodo*& cabeza, string producto, string cantidad){
    Nodo* nuevo = new Nodo;
    nuevo->nombreProducto = producto;
    nuevo->cantidad= cantidad;
    nuevo->sig = cabeza;

    cabeza = nuevo;
    cout << "Se agrego con exito"<< endl;
}

void eliminarProducto(Nodo* cabeza, string prodE){
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while(actual != nullptr){
        if(actual->nombreProducto == prodE ){
            if(anterior == nullptr){
                cabeza = actual->sig;
            }
            else{
                anterior -> sig = actual -> sig;
            }

            delete actual;
            cout << "Producto eliminado del inventario"<< endl;
            return;
        }

        anterior = actual;
        actual = actual -> sig;

    }
}

void mostrarInventario (Nodo*& head)
{
    Nodo* actual = head; // Comenzamos desde el primer nodo
    if (actual == nullptr){
        cout << "Lista vacia";
        return;
    }
    cout << "Inventario: " << endl;
    while(actual != nullptr)
    {
        cout << actual->nombreProducto << " X " << actual->cantidad << endl;


        actual = actual->sig;
    }

    cout << endl;
}
void modificarProd(Nodo* cabeza, string prodM){
    Nodo* actual = cabeza;
    bool found = false;
    string cant;

    while (actual) {
        if (actual->nombreProducto == prodM) {
            cout<< "Producto encontrado!" << endl << "Ingrese la cantidad: ";
            cin >> cant;
            actual->cantidad = cant;
            found = true;
        }
        actual = actual->sig;
    }

    if (!found) {
        cout << "Producto " << prodM << " no encontrado en la lista." << endl;
    }
}


void menu1(){
    int opcion;
    Nodo* inventario = nullptr;
    string producto, cantidad, cont ;
    do {
        cout << "Almacen de Productos" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Eliminar Productos" << endl;
        cout << "3. Mostrar Inventario" << endl;
        cout << "4. Modificar cantidad en Inventario" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del producto: ";
                cin >> producto;
                cout << "Ingrese el en inventario: ";
                cin >> cantidad;
                agregarProd(inventario, producto, cantidad);
                break;
            case 2:
                cout << "Ingrese el nombre del producto: ";
                cin >> producto;
                eliminarProducto(inventario, producto);
                break;
            case 3:
                mostrarInventario(inventario);
                break;
            case 4:
                cout << "Ingrese el nombre del producto: ";
                cin >> producto;
                modificarProd(inventario,producto);
                break;
            case 5:
                return;
            default:
                cout << "Seleccione una opcione valida";
                menu1();
                break;
        }
    }while (true);
}

int main(){
    menu1();
    return 0;
}