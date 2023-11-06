#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

void atenderClientes(){
    queue<string> filaClientes;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 10);


    filaClientes.push("cl-1");
    filaClientes.push("cl-2");
    filaClientes.push("cl-3");
    filaClientes.push("cl-4");
    filaClientes.push("cl-5");

    auto start_time = chrono::high_resolution_clock::now();

    while (!filaClientes.empty()) {
        // Generar un tiempo de espera al azar, entre 1 a 10 segundos (simulacion)
        int tiempoEspera = distribution(generator);
        this_thread::sleep_for(chrono::seconds(tiempoEspera));

        string frontString = filaClientes.front();
        filaClientes.pop();
        //Aunque son segundos, imprime "minutos" para simular.
        cout << "Se atendio: " << frontString << " (Tiempo de espera " << tiempoEspera << " minutos)" << endl;
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> execution_time = end_time - start_time;

    cout << "Tiempo total para atender clientes: " << execution_time.count() << " minutos." << endl;
}

int main() {
    //Inicio del programa.
    atenderClientes();
    return 0;
}
