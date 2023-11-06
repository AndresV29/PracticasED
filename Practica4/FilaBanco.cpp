#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>
#include <random>

using namespace std;
int main() {
    queue<std::string> myQueue;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 10);

   
    myQueue.push("cl-1");
    myQueue.push("cl-2");
    myQueue.push("cl-3");
    myQueue.push("cl-4");
    myQueue.push("cl-5");

    auto start_time = std::chrono::high_resolution_clock::now();  // tiempo de inicio

    while (!myQueue.empty()) {
        // Generar un tiempo de espera al azar, entre 1 a 10 segundos
        int wait_time = distribution(generator);
        this_thread::sleep_for(chrono::seconds(wait_time));

        string frontString = myQueue.front();
        myQueue.pop();
        cout << "Se atendio: " << frontString << " (Tiempo de espera " << wait_time << " minutos)" << endl;
    }

    auto end_time = chrono::high_resolution_clock::now();  // tiempo final
    chrono::duration<double> execution_time = end_time - start_time;

    cout << "Tiempo total para atender clientes: " << execution_time.count() << " minutos." << std::endl;

    return 0;
}
