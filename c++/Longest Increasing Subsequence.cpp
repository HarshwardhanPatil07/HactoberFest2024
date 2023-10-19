#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the Longest Increasing Subsequence (LIS).
int LIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Initialize an array to store the length of LIS ending at each index.
    vector<int> dp(n, 1);

    // Iterate through the elements to calculate LIS lengths.
    for (int i = 0; i < n; i++) {
        // Compare the current element with all previous elements.
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // If the current element is greater, update the LIS length at this index.
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = 1;
    // Find the maximum LIS length in the dp array.
    for (int i = 0; i < n; i++) {
        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int lis_length = LIS(nums);
    // Print the length of the Longest Increasing Subsequence.
    cout << "Length of Longest Increasing Subsequence: " << lis_length << endl;
    return 0;
}
