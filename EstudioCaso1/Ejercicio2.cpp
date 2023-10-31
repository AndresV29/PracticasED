//
// Created by andre on 10/26/2023.
// Gestor de contactos
#include <iostream>
#include <limits>

using namespace std;
struct Node{
    Node* sig;
    string nombreContacto, numeroTel, correoEl;
};
void agregaContacto(Node*& cabeza, string nombre, string telefono, string correo){
    Node* nuevo = new Node;
    nuevo->nombreContacto = nombre;
    nuevo->numeroTel= telefono;
    nuevo->correoEl = correo;
    nuevo->sig = cabeza;

    cabeza = nuevo;
    cout << "1 contacto nuevo fue agregado!"<< endl;
}

void eliminarContacto(Node* cabeza, string contactoE){
    Node* actual = cabeza;
    Node* anterior = nullptr;
    if (actual == nullptr){
        cout << "No existen contactos almacenados." << endl;
        return;
    }

    while(actual != nullptr){
        if(actual->nombreContacto == contactoE ){
            if(anterior == nullptr){
                cabeza = actual->sig;
            }
            else{
                anterior -> sig = actual -> sig;
            }

            delete actual;
            cout << "1 contacto ha sido eliminado."<< endl;
            return;
        }

        anterior = actual;
        actual = actual -> sig;

    }
}

void mostrarContactos (Node*& head)
{
    Node* actual = head;
    if (actual == nullptr){
        cout << "No existen contactos almacenados." << endl;
        return;
    }
    cout << "Contactos: "<< endl;
    while(actual != nullptr)
    {
        cout << actual->nombreContacto << " Numero:  " << actual->numeroTel<< " Correo: " << actual->correoEl << endl;

        actual = actual->sig;
    }

    cout << endl;
}
void buscarContacto(Node* cabeza, string contactoB){
        Node* current = cabeza;
        bool found = false;

        while (current) {
            if (current->nombreContacto == contactoB) {
                cout << "Contacto fue encontrado " << contactoB << "Numero: " << current->numeroTel <<endl;
                found = true;
            }
            current = current->sig;
        }

        if (!found) {
            cout << "Contacto " << contactoB << " no encontrado en la lista." << endl;
        }

}


void menu(){
    int opcion;
    Node* inventario = nullptr;
    string nom, num,email;
    do {
        cout << "Gestor de Contactos" << endl;
        cout << "1. Agregar Contacto" << endl;
        cout << "2. Eliminar Contacto" << endl;
        cout << "3. Mostrar lista de Contactos" << endl;
        cout << "4. Buscar contacto." << endl;
        cout << "5. Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del contacto: ";
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, nom);
                //cin >> nom;
                cout << "Ingrese el numero de telefono: ";
                cin >> num;
                cout << "Ingrese el correo electronico del contacto: ";
                cin >> email;
                agregaContacto(inventario, nom, num, email);
                break;
            case 2:
                cout << "Ingrese el nombre del contacto: ";
                cin >> nom;
                eliminarContacto(inventario, nom);
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
                menu();
                break;
        }
    }while (true);
}
int main(){
   menu();
   return 0;
}