#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <chrono>

constexpr unsigned long long ITERATIONS_PER_THREAD = 1000000000; // Adjust as needed

// Function to perform a CPU-intensive computation
void compute() {
    // Perform some CPU-intensive computation
    for (unsigned long long i = 0; i < ITERATIONS_PER_THREAD; ++i) {
        // Here you can perform any computation that takes CPU cycles
        // For simplicity, we'll just perform some arithmetic operations
        volatile double result = std::sqrt(std::sin(i) * std::cos(i));

        // if i is modulus of 1000000, print the value of i
        if (i % 1000000 == 0) {
			std::cout << "Thread ID: " << std::this_thread::get_id() << " i: " << i << std::endl;
		}
    }
}

int main() {
    int test = 0;
    
    // Get the number of CPU cores
    unsigned int num_cores = std::thread::hardware_concurrency();
    std::cout << "Number of CPU cores: " << num_cores << std::endl;

    std::cin >> test;

    std::cout << "Testing Cores";

    // Create a vector to hold thread objects
    std::vector<std::thread> threads;

    // Start threads to utilize all CPU cores
    for (unsigned int i = 0; i < num_cores; ++i) {
        threads.emplace_back(compute);
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "All threads have finished." << std::endl;

    return 0;
}
