#include <iostream>

using namespace std;

void rellenaArreglo(int arr[], int tam){

    for (int i = 0; i < tam; ++i) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void ordenaInsercion(int arr[], int size){
    int aux, pos;
    for (int i = 0; i < size; ++i) {
        pos = i;
        aux = arr[i];
        while((pos > 0) && (arr[pos-1])> aux){
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = aux;
    }
}


void muestraArreglo(int arr[], int tam){
    cout << "Orden Acendente: " << endl;
    for (int i = 0; i < tam; ++i) {
        cout << arr[i] << " ";
    }
}




int main() {
    int cantidad = 0;
    string respuesta;

    while(true) {
        cout << "Ingrese la cantidad de numeros que desea ordenar: " << endl;
        cin >> cantidad;
        int nums[cantidad];
        
        rellenaArreglo(nums, cantidad);

        ordenaInsercion(nums, cantidad);

        muestraArreglo(nums, cantidad);
        cout << " \n Desea ordenar otro conjuntos de numeros? (s/n): ";
        cin >> respuesta;
        if (respuesta == "n") break;
    }
    return 0;
}
