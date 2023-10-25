//
// Created by andre on 10/24/2023.
//

//#include "Gestor.h"
//#include "PilaLlamadas.h"
//#include <iostream>
//
//using namespace std;
//PilaLlamadas miPila;
//
//void capturaDatos(){
//    string nombre, estado;
//    int numero;
//    cout<< "Ingrese el numero: ";
//    cin >> numero;
//    cout<< "Ingrese el nombre: ";
//    cin >> numero;
//    cout<< "Ingrese el estado de la llamada: ";
//    cin >> numero;
//    Llamada nueva(numero,nombre,estado);
//    //return ll
//    miPila.registraLlamada(nueva);
//}
//
//
//void menu(){
//    int opcion;
//    string continuar;
//
//    while (true){
//        cout << "Gestor de Llamadas \n 1.Registrar Llamada \n 2.Atender ultima llamada \n 3.Mostrar llamada mas reciente 4. Mostrar todas las llamadas. 5. salir";
//        switch (opcion) {
//            case 1:
//                capturaDatos();
//                break;
//            case 2:
//                miPila.atenderUltimaLlamada();
//                break;
//            case 3:
//                miPila.mostrarUltimaLlamada();
//                break;
//            case 4:
//                miPila.mostrarTodo();
//                break;
//            case 5:
//                return;
//            default:
//                cout << "Opcion seleccionada no es valida."<< endl;
//                return;
//        }
//        cout << "Desea realizar otra accion? (s/n)";
//        cin >> continuar;
//        if (continuar == "n"){
//            return;
//        }
//
//    }
//}