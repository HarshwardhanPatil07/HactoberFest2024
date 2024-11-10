
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if cows can be placed with at least 'dist' distance apart
bool isFeasible(vector<int> &stalls, int n, int k, int dist) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0]; // Position of the last placed cow

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= dist) {
            count++; // Place another cow
            last_position = stalls[i]; // Update last position
            if (count == k) {
                return true; // All cows placed successfully
            }
        }
    }
    return false; // Not all cows could be placed with the given distance
}

int aggressiveCows(vector<int> &stalls, int n, int k) {
    sort(stalls.begin(), stalls.end()); // Sort stall positions

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isFeasible(stalls, n, k, mid)) {
            result = mid; // Update result if feasible
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }

    return result;
}

int main() {
    int n = 5; // Number of stalls
    int k = 3; // Number of cows
    vector<int> stalls = {1, 2, 8, 4, 9}; // Positions of the stalls

    cout << "Maximum minimum distance is " << aggressiveCows(stalls, n, k) << endl;

    return 0;
}
