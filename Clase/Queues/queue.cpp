#include <iostream>
#include <queue>

using namespace std;
int main() {
    //declarar cola
    queue<int> miCola;
    //insertar datos
    miCola.push(10);
    miCola.push(20);
    miCola.push(30);
    // 30 -> 20 -> 10
    //eliminar datos
    miCola.pop();//Elimina primer elemento de la cola (10)
    // 30 -> 20

    //Primer dato
    int dato = miCola.front();
    cout <<"Primer dato:" << dato << endl;
    //Ultimo dato
    int datoU = miCola.front();
    cout <<"Ultimo dato:" << datoU << endl;

    //Empty
    if (miCola.empty()){
        cout << "La cola se encuentra vacia" << endl;
    }else  {
        cout << "La cola no se encuentra vacia"<< endl;
    }

    //Size
    int tam = miCola.size();
    cout << "Cantidad de datos dentro de cola: " << endl;
    return 0;
}
