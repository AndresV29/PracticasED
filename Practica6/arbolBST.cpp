#include <iostream>

using namespace std;
struct Nodo{
    int dato;
    Nodo *izq, *der, *padre;
};
//Insertar
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
//Search
Nodo *search( Nodo* root, int key) {

    if (root == nullptr || root->dato == key) {
        return root;
    }
    if (root->dato < key) {

        return search(root->der, key);
    }
    return search(root->izq, key);
}
//Recorrer en orden
void inOrder(Nodo *&arbol){
    if (arbol == nullptr){
        cout << "No se encuentran datos registrados";
        return;
    }else {
        inOrder(arbol->izq);
        cout << arbol->dato<<" - ";
        inOrder(arbol->der);
    }
}
//Altura
int alturaArbol(Nodo *&arbol) {
    if (arbol == nullptr)
        return 0;
    else {
        int altIzquierda = alturaArbol(arbol->izq);
        int altDerecha = alturaArbol(arbol->der);

        return max(altIzquierda, altDerecha) + 1;
    }
}
bool menu(){
    int dato, opcion;
    Nodo *arbol = nullptr;
    do {
        cout << "Menu arbol bin \n 1. Insertar dato. \n 2. Mostrar arbol. \n 3. Recorrer arbol. \n4. Recorrer en orden \n 5 Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el numero: ";
                cin >> dato;
                insertarNodo(arbol, dato, nullptr);
                break;
            case 2:
                //Search
                cout << "Ingrese el numero que desea buscar: ";
                cin >> dato;
                search(arbol, dato);
                if (search(arbol, dato) == nullptr) cout << "El valor ingresdo no se encuentra registrado" << endl;
                else cout << "El valor: " << dato << " se encuentra registrado"<<endl;
                break;
            case 3:
                inOrder(arbol);
                break;
            case 4:
                //altura
                alturaArbol(arbol);
                if (alturaArbol(arbol) == 0) cout << "Actualmente no hay datos registrados" << endl;
                else cout << "Altura del arbol: " << alturaArbol(arbol) << endl;
                break;
            case 5:
                cout << "Que tenga buen dia!"<< endl;
                return false;
            default:
                cout << "Opcion seleccionada no es valida" << endl;
                return false;

        }
    } while (true);
}

int main() {
    menu();
    return 0;
}
