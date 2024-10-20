#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to place cows with minimum distance 'mid'
bool canPlaceCows(const vector<int>& stalls, int cows, int mid) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_position >= mid) {
            // Place the next cow
            count++;
            last_position = stalls[i];
            if (count == cows) return true;
        }
    }
    return false;
}

int aggressiveCows(const vector<int>& stalls, int cows) {
    int n = stalls.size();
    
    // Sort the stalls to apply binary search
    vector<int> sorted_stalls = stalls;
    sort(sorted_stalls.begin(), sorted_stalls.end());

    // Set the bounds for binary search
    int low = 1; // Minimum possible distance
    int high = sorted_stalls[n-1] - sorted_stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(sorted_stalls, cows, mid)) {
            result = mid;  // Mid is a valid solution, try for a larger minimum distance
            low = mid + 1;
        } else {
            high = mid - 1;  // Mid is too large, try for a smaller minimum distance
        }
    }

    return result;
}

int main() {
    int n;
    cout<<"Enter the no. of stalls:"<<endl;
    cin>>n;
    vector<int> stalls (n);
    int cows;
    cout<<"Enter the no. of cows :"<<endl;
    cin>>cows;
    cout<<"Enter the positions of the cows:"<<endl;
    for(int i=0;i<n;i++)
    cin>>stalls[i];
    int maxDistance = aggressiveCows(stalls, cows);
    cout << "The largest minimum distance is: " << maxDistance << endl;

    return 0;
}
