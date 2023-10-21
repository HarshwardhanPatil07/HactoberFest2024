// Github Username - Sykikxo
// Aim - implement bogosort algorithm, inputs a array of numbers, returns sorted array, and the time and iterations taken to sort.
// Date - 21 October, 2023

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>

void bogosort(std::vector<int>& arr, int& iterations) {
    std::random_device rd;
    std::mt19937 g(rd());
    while (!std::is_sorted(arr.begin(), arr.end())) {
        std::shuffle(arr.begin(), arr.end(), g);
        iterations++;
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    std::vector<int> arr(size);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int iterations = 0;
    auto start = std::chrono::high_resolution_clock::now();
    bogosort(arr, iterations);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Sorted array: ";
    for (auto num : arr) {
        std::cout << num << ' ';
    }
    std::cout << "\nNumber of iterations: " << iterations;
    std::cout << "\nTime taken to sort: " << elapsed.count() << " seconds\n";
    return 0;
}
