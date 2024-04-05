#include <iostream>
#include <thread>
#include <vector>
#include <cmath>

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0)
            return false;
    }
    return true;
}

// Function to simulate high CPU utilization
void simulateHighCPU() {
    int number = 2;
    while (true) {
        // Check if the number is prime
        if (isPrime(number)) {
            std::cout << number << " is prime." << std::endl;
        }
        number++;
    }
}

int main() {
    	int test = 0;

    // Get the number of CPU cores1
    unsigned int num_cores = std::thread::hardware_concurrency();
    std::cout << "Number of CPU cores: " << num_cores << std::endl;

    std::cin >> test;

    // Create a vector to hold thread objects
    std::vector<std::thread> threads;

    // Create a thread for each CPU core
    for (unsigned int i = 0; i < num_cores; ++i) {
        threads.push_back(std::thread(simulateHighCPU));
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    std::cin >> test;

    return 0;
}
