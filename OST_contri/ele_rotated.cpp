#include <iostream>
#include <vector>
using namespace std;

// Function to find the index of target in rotated sorted array
int searchInRotatedArray(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If target is found, return the index
        if (nums[mid] == target)
            return mid;

        // Determine which part is sorted
        if (nums[left] <= nums[mid]) {  // Left side is sorted
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;  // Search in the left half
            } else {
                left = mid + 1;  // Search in the right half
            }
        } else {  // Right side is sorted
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;  // Search in the right half
            } else {
                right = mid - 1;  // Search in the left half
            }
        }
    }

    // If not found, return -1
    return -1;
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    int result = searchInRotatedArray(nums, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
