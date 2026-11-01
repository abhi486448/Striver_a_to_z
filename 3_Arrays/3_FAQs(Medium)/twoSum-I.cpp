#include<bits/stdc++.h>
using namespace std;

// 1. Two Sum
// Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.

// Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in any order.

// Example 1:
// Input: nums = [1, 6, 2, 10, 3], target = 7
// Output: [0, 1]
// Explanation:
// nums[0] + nums[1] = 1 + 6 = 7
// Example 2:
// Input: nums = [1, 3, 5, -7, 6, -3], target = 0
// Output: [1, 5]
// Explanation:
// nums[1] + nums[5] = 3 + (-3) = 0
// Constraints:
// 2 <= nums.length <= 105
// -104 <= nums[i] <= 104
// -105 <= target <= 105
// Only one valid answer exists.

// brute
vector<int> brutTwoSum(vector<int> &nums, int target){
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(target-nums[i]==nums[j]){
                return {i, j};
            }
        }
    }
    return {};
}
// complexcity
// time O(n*n);

// better
vector<int> betterTwoSum(vector<int> &nums, int target){
    map<int, int> mpp;
    for(int i=0; i<nums.size(); i++){
        int a = nums[i];
        int more = target-a;
        if(mpp.find(more)!=mpp.end()){
            return {i, mpp[more]};
        }
        mpp[a]= i;
    }
    return {};
}
// complexcity
// time O(n log n);
// space n;

int main(){
    vector<int> nums={1,3,5,-7,6,-3};
    int target = 0;
    // vector<int> ans = brutTwoSum(nums, target);
    vector<int> ans = betterTwoSum(nums, target);

    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}