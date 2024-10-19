//Gituhb username: Nikhileshmauje
//Aim: Solution and approaches to Majority element question of Leetcode
//Date: 19th October 2024

#include <iostream>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

// Brute Force O(n^2)
int majorityElement(vector<int> nums)
{
    int n = nums.size();
    for (int val : nums)
    {
        int freq = 0;
        for (int el : nums)
        {
            if (el == val)
            {
                freq++;
            }
        }
        if (freq > n / 2)
        {
            return val;
        }
    }
    return -1;
}

// Using Sorted array
int majorityElementBetter(vector<int> &nums)
{

    int n = nums.size();

    sort(nums.begin(), nums.end());

    int freq = 1, ans = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {

            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }

        if (freq > n / 2)
        {
            return ans;
        }
    }
    return ans;
}

//Moore's voting algotrithm
int majorityElementMr(vector<int> &nums){

    int freq = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
        {
            ans = nums[i];
        }
        if (ans == nums[i])
        {
            freq++;
        }
        else
        {
            freq--;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {2, 1, 1, 1, 1, 2};
    int n = vec.size();

    cout << "Value using Brute Force approach is: " << majorityElement(vec) << endl;

    cout<<"value using Sorting approach is: "<<majorityElementBetter(vec)<<endl;

    cout<<"value using Moore's Voting Algorithm is: "<<majorityElementMr(vec)<<endl;
}