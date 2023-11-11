#include <iostream>

using namespace std;
void ordenaNumeros(int miArreglo[], int size) {
    for (int i = 1; i < size; ++i) {
        int pos = miArreglo[i];
        int j = i - 1;
        while (j >= 0 && miArreglo[j] > pos) {
            miArreglo[j + 1] = miArreglo[j];
            --j;
        }
        miArreglo[j + 1] = pos;
    }
}

void insertArreglo(int miArreglo[], int tam){
    cout << "Ingrese " << tam << " elementos para el arreglo:\n";
    for (int i = 0; i < tam; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> miArreglo[i];
    }
}
void muestraArreglo(int miArreglo[], int tam){
    std::cout << "Arreglo ordenado en orden ascendente: ";
    for (int i = 0; i < tam; ++i) {
        std::cout << miArreglo[i] << " ";
    }
}

int main() {
    int cantidad;
    string respuesta;
    bool continuar = true;
    while (true) {
        cout << "Ingrese la cantidad de numeros que desea ordenar: ";
        cin >> cantidad;

        int numeros[cantidad];

        //Insertar elementos.
        insertArreglo(numeros, cantidad);

        // Llamar ordenamiento por insercion.
        ordenaNumeros(numeros, cantidad);

        // Imprimir arreglo ordenado de menor a mayor.
        muestraArreglo(numeros, cantidad);

        cout << " \n Desea ordenar otro conjuntos de numeros? (s/n): ";
        cin >> respuesta;
        if (respuesta == "n") break;
    }



    return 0;
}

