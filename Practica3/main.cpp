#include "PilaLlamadas.h"
#include <iostream>

using namespace std;

PilaLlamadas miPila;

void capturaDatos(){
    string nombre, estado;
    int numero;
    cout<< "Ingrese el numero: ";
    cin >> numero;
    cout<< "Ingrese el nombre: ";
    cin >> numero;
    cout<< "Ingrese el estado de la llamada: ";
    cin >> numero;
    Llamada nueva(numero,nombre,estado);
    miPila.registraLlamada(nueva);
}


void menu(){
    int choice;

    while (true) {
        cout << "Main Menu" << endl;
        cout << "1. Option 1" << endl;
        cout << "2. Option 2" << endl;
        cout << "3. Option 3" << endl;
        cout << "4. Option 4" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You selected Option 1" << endl;
                // Add code for Option 1 here
                break;
            case 2:
                cout << "You selected Option 2" << endl;
                // Add code for Option 2 here
                break;
            case 3:
                cout << "You selected Option 3" << endl;
                // Add code for Option 3 here
                break;
            case 4:
                cout << "You selected Option 4" << endl;
                // Add code for Option 4 here
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
int main(){
    menu();
    return 0;
}
