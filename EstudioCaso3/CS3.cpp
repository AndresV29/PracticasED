#include <iostream>
/*
 * Andres Villalobos Carballo
 * Respuestas a puntos 3 y 4, se encuentran en el pdf adjunto.*/
using namespace std;
struct Nodo{
    int dato;
    Nodo *izq, *der, *padre;


};

// Insercion
Nodo *crearNodo(int n, Nodo *padre){
    Nodo  *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->der = nullptr;
    nuevo->izq = nullptr;
    nuevo->padre = padre;
    return nuevo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
    if (arbol== nullptr) {
        Nodo *nuevo = crearNodo(n, padre);
        arbol = nuevo;
    } else{
        //obtener valor de la raiz
        int valorRaiz = arbol->dato;
        if (n<valorRaiz){
            //asignar a izquierda
            insertarNodo(arbol->izq, n, padre);
        } else{
            //asignar a derecha
            insertarNodo(arbol->der, n, padre);
        }
    }
}
//Borrado
Nodo *deleteNode(Nodo *&root, int k)
{
    if (root == nullptr) {
        cout << "No hay datos que se puedan eliminar." << endl;
        return root;
    }

    if (root->dato > k) {
        root->izq = deleteNode(root->izq, k);
        return root;
    }
    else if (root->dato < k) {
        root->der = deleteNode(root->der, k);
        return root;
    }


    if (root->izq == nullptr) {
        Nodo* temp = root->der;
        delete root;
        return temp;
    }
    else if (root->der == nullptr) {
        Nodo* temp = root->izq;
        delete root;
        return temp;
    }
    else {

        Nodo* succParent = root;


        Nodo* succ = root->der;
        while (succ->izq != NULL) {
            succParent = succ;
            succ = succ->izq;
        }


        if (succParent != root)
            succParent->izq = succ->der;
        else
            succParent->der = succ->der;

        root->dato = succ->dato;

        delete succ;
        return root;
    }
}
//Busqueda
Nodo *search( Nodo *&root, int key) {

    if (root == nullptr || root->dato == key) {
        return root;
    }
    if (root->dato < key) {

        return search(root->der, key);
    }
    return search(root->izq, key);
}
//2. Recorrido en orden
void inOrder(Nodo *&arbol){
    if (arbol == NULL){
        return;
    }else {
        inOrder(arbol->izq);
        cout << arbol->dato<<" - ";
        inOrder(arbol->der);
    }
}

// Menu
bool menu(){
    int dato, opcion;
    Nodo *arbol = nullptr;
    do {
        cout << "\n Menu \n 1. Insertar dato. \n 2. Eliminar Dato. \n 3. Buscar Dato. \n 4.Recorrido en orden \n 5 Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el numero que desea agregar: ";
                cin >> dato;
                insertarNodo(arbol, dato, nullptr);
                break;
            case 2:
                cout << "Ingrese el numero que desea eliminar: ";
                cin >> dato;
                deleteNode(arbol, dato);
                break;
            case 3:
                //search
                cout << "Ingrese el numero que desea buscar: ";
                cin >> dato;
                if (search(arbol, dato)) cout << " Dato encontrado" << endl;
                break;
            case 4:
                inOrder(arbol);
                break;
            case 5:
                cout << "Adios";
                return false;
            default:
                cout << "Opcion invalida.";
                return false;
        }
    } while (true);
}


int main() {
    menu();
}
