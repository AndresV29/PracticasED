/*
 * Caso Estudio 2
 * Cola de Pedidos
 * Andres Villalobos Carballo*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Pedido{
    string codigo;
    float monto;
    Pedido(string basicString, float i) {}
};

//Encolar
void agregarPedidos(queue<Pedido> pedidos, string codigo, float monto){
    Pedido nuevo(codigo, monto);
    pedidos.push(nuevo);
    cout << "Se ha agregado el pedido a la cola.";
}
//Ordenar
void ordenarPedidos(queue<Pedido>& pedidos) {
    vector<Pedido> pedidosVec;
    while (!pedidos.empty()){
        pedidosVec.push_back(pedidos.front());
        pedidos.pop();
    }
    for (int i = 0; i < pedidosVec.size(); ++i) {
        for (int j = 0; j < pedidosVec.size() - i - 1; ++j) {
            if (pedidosVec[j].monto > pedidosVec[j + 1].monto ){
                swap(pedidosVec[j], pedidosVec[j + 1]);
            }
        }
    }
    for (const auto& order : pedidosVec) {
        pedidos.push(order);
    }
}
//Buscar
bool buscar(queue<Pedido>& orders, const string& codigoB) {
    queue<Pedido> temp = orders;
    Pedido *found = nullptr;

    while (!temp.empty()) {
        if (temp.front().codigo == codigoB) {
            *found = temp.front();
            cout << "El pedido se encuentra en la cola!";
            return true;
        }
        temp.pop();
    }

    return false;
}
void atenderPedidos(queue<Pedido>& orders){\
    queue<Pedido> tempCola = orders;

    cout << "Se van a atender los siguientes 3 pedidos: :" << endl;
    while (!tempCola.empty()) {
        std::cout << "Codigo del pedido: " << tempCola.front().codigo << ", Monto: " << tempCola.front().monto << " - ";
        tempCola.pop();
    }
    while (!orders.empty()){
        orders.pop();
        cout << "Se procesaron los pedidos ingresado";
    }
}
//Procesar
void procesarPedidos(queue<Pedido>& orders){
    float monto;
    string cod;
    //1. agregar 3 pedidos
    while (orders.size()<3){
        cout << "Ingrese el codigo del pedido: "<< endl;
        cin >> cod;
        cout << "Ingrese el monto del pedido: "<< endl;
        cin >> monto;
        agregarPedidos(orders,cod, monto);
    }
    //2. ordenar por monto
    ordenarPedidos(orders);
    //3. buscar
    cout << "Ingrese el codigo del pedido que desea buscar: "<< endl;
    cin >> cod;
    buscar(orders, cod);
    //4. Desencolar
    atenderPedidos(orders);
}
void menu(){
    int opcion;
    queue<Pedido> misPedidos;
    string codigo;
    float monto;
    do {
        cout << "Gestor de Pedidos" << endl;
        cout << "1. Agregar Pedido" << endl;
        cout << "2. Ordenar cola de Pedidos" << endl;
        cout << "3. Buscar pedido" << endl;
        cout << "4. Procesar 3 pedidos" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                //agregar
                cout << "Ingrese el codigo del pedido: "<< endl;
                cin >> codigo;
                cout << "Ingrese el monto del pedido: "<< endl;
                cin >> monto;
                agregarPedidos(misPedidos,codigo, monto);
                break;
            case 2:
                //ordenar por monto
                ordenarPedidos(misPedidos);
                break;
            case 3:
                //buscar por codigo
                cout << "Ingrese el codigo del pedido que desea buscar: "<< endl;
                cin >> codigo;
                buscar(misPedidos, codigo);
                break;
            case 4:
                //atender 3 pedidos
                procesarPedidos(misPedidos);
                break;
            case 5:
                cout << "Que tenga buen dia";
                return;
            default:
                cout << "Opcion seleccionada no es valida";
                return;
        }
    }while (true);
}



int main(){
    menu();
    return 0;
}