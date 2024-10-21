#include <iostream>
#include <vector>
#include <algorithm>

/*

Given an integer array nums, 
return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

*/
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int sum = nums[l] + nums[r] + nums[i];

            if (sum == 0) {
                result.push_back({nums[i], nums[l], nums[r]});
                l++, r--;

                while (l < r && nums[l] == nums[l - 1])
                    l++;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            } else if (sum < 0) {
                l += 1;
            } else {
                r -= 1;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums2 = {0, 1, 1};
    vector<int> nums3 = {0, 0, 0};

    vector<vector<int>> result1 = threeSum(nums1);
    vector<vector<int>> result2 = threeSum(nums2);
    vector<vector<int>> result3 = threeSum(nums3);

    for (const auto& triplet : result1) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "----" << endl;
    
    for (const auto& triplet : result2) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "----" << endl;

    for (const auto& triplet : result3) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
