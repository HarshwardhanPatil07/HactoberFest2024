#include <iostream>
#include <unordered_map>
#include <vector>

/*
Problem: Two Sum

Given an array of integers `nums` and an integer `target`,
return the indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3, 2, 4], target = 6
Output: [1, 2]
Explanation: Because nums[1] + nums[2] == 6, we return [1, 2].

Example 3:
Input: nums = [3, 3], target = 6
Output: [0, 1]
Explanation: Because nums[0] + nums[1] == 6, we return [0, 1].
*/

using namespace std;

vector<int> twoSum(const vector<int> &nums, int target) {
  unordered_map<int, int> num_map; // To store the number and its index
  for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i]; // Find the complement
    if (num_map.find(complement) != num_map.end()) {
      return {num_map[complement], i}; // Return the indices
    }
    num_map[nums[i]] = i; // Store the number and its index
  }
  return {}; // In case no solution is found (should not happen as per problem
             // statement)
}

int main() {
  // Test cases
  vector<int> nums1 = {2, 7, 11, 15};
  int target1 = 9;
  vector<int> result1 = twoSum(nums1, target1);
  cout << "Indices: [" << result1[0] << ", " << result1[1] << "]\n";

  vector<int> nums2 = {3, 2, 4};
  int target2 = 6;
  vector<int> result2 = twoSum(nums2, target2);
  cout << "Indices: [" << result2[0] << ", " << result2[1] << "]\n";

  vector<int> nums3 = {3, 3};
  int target3 = 6;
  vector<int> result3 = twoSum(nums3, target3);
  cout << "Indices: [" << result3[0] << ", " << result3[1] << "]\n";

  return 0;
}
