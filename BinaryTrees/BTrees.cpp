#include <iostream>

using namespace std;
struct Nodo{
    int dato;
    Nodo *izq, *der;

    // izq <- dato -> der
};

// Primer paso
Nodo *crearNodo(int n){
    Nodo  *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->der = nullptr;
    nuevo->izq = nullptr;
    return nuevo;
}

//Segundo paso
void insertarNodo(Nodo *&arbol, int n){
    if (arbol== nullptr) {
        Nodo *nuevo = crearNodo(n);
        arbol = nuevo;
    } else{
        //obtener valor de la raiz
        int valorRaiz = arbol->dato;
        if (n<valorRaiz){
            //asignar a izquierda
            insertarNodo(arbol->izq, n);
        } else{
            //asignar a derecha
            insertarNodo(arbol->der, n);
        }
    }
}
//Tercer paso
void mostrarArbol(Nodo *&arbol, int cont ){
    if (arbol == nullptr) return;

    mostrarArbol(arbol->der, cont + 1);
    for (int i = 0; i < cont; ++i) {
        cout << "   ";
    }
    cout << arbol->dato << endl;
    mostrarArbol(arbol->izq, cont + 1);
}

// Menu
bool menu(){
    int dato, opcion;
    Nodo *arbol = nullptr;
    do {
        cout << "Menu arbol bin \n 1. Insertar dato. \n 2. Mostrar arbol. \n 3. Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el numero: ";
                cin >> dato;
                insertarNodo(arbol, dato);
                break;
            case 2:
                mostrarArbol(arbol, 0);
                break;
            case 3:
                cout << "Adios";
                return false;
            default:
                cout << " I said good day";
                return false;
        }
    } while (true);
}


int main() {
    menu();
}
