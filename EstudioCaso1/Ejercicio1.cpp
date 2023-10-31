//
// Created by andre on 10/25/2023.
//Almacen de productos
#include <iostream>
#include <vector>
#include <list>
#include <limits>
using namespace std;

struct Nodo{
    Nodo* sig;
    string nombreProducto;
    int cantidad, precioUnitario;
};
void agregarProd(Nodo*& cabeza, string producto, int cantidad, int precio){
    Nodo* nuevo = new Nodo;
    nuevo->nombreProducto = producto;
    nuevo->cantidad= cantidad;
    nuevo->precioUnitario =  precio;
    nuevo->sig = cabeza;

    cabeza = nuevo;
    cout << "Se agrego con exito el producto"<< endl;
}

void eliminarProducto(Nodo* cabeza, string prodE){
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    if (cabeza == nullptr) cout << "No existen productos dentro del inventario" << endl;

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
    Nodo* actual = head;
    if (actual == nullptr) cout << "No existen productos dentro del inventario"  << endl;

    cout << "Inventario: " << endl;
    while(actual != nullptr)
    {
        cout << "Nombre: " << actual->nombreProducto << " Cantidad: " << actual->cantidad<< " Precio unitario:  "<< actual->precioUnitario << endl;
        actual = actual->sig;
    }
    cout << endl;
}
void modificarProd(Nodo* cabeza, string prodM){
    Nodo* actual = cabeza;
    bool found = false;
    int cant;

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
        cout << "Producto " << prodM << " no fue encontrado en el inventario." << endl;
    }
}
float valorInventario(Nodo* cabeza){
    float valorTotal;
    Nodo* actual = cabeza;
    while (actual){
        valorTotal += actual->precioUnitario * actual->cantidad;
        actual = actual->sig;
    }
    cout << "El inventario posee un valor total de: " << valorTotal << endl;
    return valorTotal;
}


void menu1(){
    int opcion;
    Nodo* inventario = nullptr;
    string producto, cont ;
    int cantidad, precio;
    do {
        cout << "Almacen de Productos" << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Eliminar Producto" << endl;
        cout << "3. Mostrar Inventario" << endl;
        cout << "4. Modificar cantidad en Inventario" << endl;
        cout << "5. Calcular valor total del Inventario" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del producto: ";
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, producto);
                cout << "Ingrese la cantidad en inventario: ";
                cin >> cantidad;
                cout << "Ingrese el precio unitario: ";
                cin >> precio;
                agregarProd(inventario, producto, cantidad, precio);
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
                valorInventario(inventario);
                break;
            case 6:
                cout << "Que tenga buen dia";
                return;
            default:
                cout << "Seleccione una opcion valida";
                menu1();
                break;
        }
    }while (true);
}

int main(){
    menu1();
    return 0;
}