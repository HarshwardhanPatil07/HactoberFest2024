#include <iostream>
#include <unordered_set>

int main() {
    int arr[] = {4, 2, 7, 2, 1, 8, 7, 6, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::unordered_set<int> seen;
    bool hasDuplicates = false;

    std::cout << "Duplicate elements in the array: ";
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            if (hasDuplicates) {
                std::cout << ", ";
            }
            std::cout << arr[i];
            hasDuplicates = true;
        } else {
            seen.insert(arr[i]);
        }
    }

    if (!hasDuplicates) {
        std::cout << "No duplicates found.";
    }

    std::cout << std::endl;

    return 0;
}
