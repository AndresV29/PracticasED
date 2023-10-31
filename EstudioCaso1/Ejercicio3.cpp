//
// Created by andre on 10/28/2023.
//Estacionamiento con pila

#include <iostream>
#include <stack>
#include <limits>
#include <sstream>
using namespace std;
struct Auto {
    string modelo, placa;
    int pos;
};
stack<Auto> estacionamiento;

void agregaAuto(Auto nuevo){
    if (estacionamiento.size() == 5){
        cout << "El estacionamiento se encuentra en su capacidad maxima, no es posible agregar otro auto.";
    }else {
        estacionamiento.push(nuevo);
        cout << "El auto ha ingresado al estacionamiento"<< endl;
    }

}

void eliminaAuto(){
    cout << "Un auto se ha retirado del Estacionamiento";
    estacionamiento.pop();
}
Auto eliminaUltimo(){
    Auto temp = estacionamiento.top();
    estacionamiento.pop();
    return temp;
}
void mostrarAutos(){
    
    stack<Auto> temp;
    Auto valorPivote;
    int tam = estacionamiento.size();
    cout << "Autos Estacionados: "<< tam << endl;
    if (tam == 5){
        cout << "\n El estacionamiento esta en capacidad maxima." << endl;
    }else if (tam < 5)  {
        cout << "\n El estacionamiento no se encuentra en su maxima capacidad. " << endl;
    }else if (estacionamiento.empty()){
        cout << "El estacionamiento se encuentra vacio" << endl;
    }
    for(int i = 0; i < tam; i++){
        valorPivote =  eliminaUltimo();
        cout << "Placa: " << valorPivote.placa << " Modelo: "<< valorPivote.modelo << " Posicion:" << valorPivote.pos << endl;
        temp.push(valorPivote);
    }
    tam = temp.size();
    for(int i = 0; i < tam; i++){
        valorPivote = temp.top();
        temp.pop();
        estacionamiento.push(valorPivote);
    }
}

void menuEst(){
    int opcion;
    string modelo, placa;
    Auto nuevo;
    do {
        cout << "Estacionamiento" << endl;
        cout << "1. Registrar Auto" << endl;
        cout << "2. Eliminar Auto" << endl;
        cout << "3. Mostrar estado del estacionamiento" << endl;
        cout << "4. Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el modelo del auto: ";
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                getline(cin, nuevo.modelo);
                //cin >> nom;
                cout << "Ingrese la placa del vehiculo: ";
                cin >> nuevo.placa;
                cout << "Ingrese la posicion donde se encuentra el vehiculo(1-5) ";
                cin >> nuevo.pos;
                agregaAuto(nuevo);
                break;
            case 2:
                eliminaAuto();
                break;
            case 3:
                 mostrarAutos();
                break;
            case 4:
                return;
            default:
                cout << "Seleccione una opcion valida";
                menuEst();
                break;
        }
    }while (true);
}

int main(){
   menuEst();
   return 0;
}