#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>
#include <random>

int main() {
    std::queue<std::string> myQueue;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 10);

    // Add five strings to the queue
    myQueue.push("String 1");
    myQueue.push("String 2");
    myQueue.push("String 3");
    myQueue.push("String 4");
    myQueue.push("String 5");

    auto start_time = std::chrono::high_resolution_clock::now();  // Record the start time

    while (!myQueue.empty()) {
        // Generate a random wait time between 1 and 10 seconds
        int wait_time = distribution(generator);
        std::this_thread::sleep_for(std::chrono::seconds(wait_time));

        // Pop and print the front string
        std::string frontString = myQueue.front();
        myQueue.pop();
        std::cout << "Popped: " << frontString << " (Waited for " << wait_time << " seconds)" << std::endl;
    }

    auto end_time = std::chrono::high_resolution_clock::now();  // Record the end time
    std::chrono::duration<double> execution_time = end_time - start_time;

    std::cout << "Program executed in " << execution_time.count() << " seconds." << std::endl;

    return 0;
}
