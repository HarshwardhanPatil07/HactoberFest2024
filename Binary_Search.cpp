#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To prevent overflow

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found at index mid
        }
        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40}; // Sorted array
    int target = 10;

    int result = binarySearch(arr, target);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
