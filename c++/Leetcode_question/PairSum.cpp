//Gituhb username: Nikhileshmauje
//Aim: Solution and approaches to Pair Sum question of Leetcode
//Date: 19th October 2024

#include<iostream>
#include<climits>
#include<vector>
using namespace std;


//Pair Sum - Brute Force Approach
vector<int> pairSum(vector<int> nums, int target){

    vector<int> ans;

    int n=nums.size();

    for(int i=0 ;i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

//Pair sum Optimized approach
vector<int> pairSumOp(vector<int> nums, int target){
    
    vector<int> ans;

    int n=nums.size();

    int i=0,j=n-1;
    while(i<j){
        int ps=nums[i]+nums[j];
        if(ps>target){
            j--;
        } else if(ps<target){
            i++;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }

    }

}

int main(){
    vector<int> vec={2,7,11,15};
    int target=22;

    cout<<"Brute Force Approach: "<<endl;
    vector<int> ans= pairSum(vec, target);
    cout<<"first: "<<ans[0]<<endl;
    cout<<"second: "<<ans[1]<<endl;

    cout<<"Optimized Two pointer Approach:"<<endl;
    vector<int> ans1= pairSumOp(vec, target);
    cout<<"first: "<<ans1[0]<<endl;
    cout<<"second: "<<ans1[1]<<endl;


    return 0;
}

