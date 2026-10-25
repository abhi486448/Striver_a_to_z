#include<bits/stdc++.h>
using namespace std;

// 237. Left Rotate Array by K Places
// Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.

// Example 1:
// Input: nums = [1, 2, 3, 4, 5, 6], k = 2
// Output: nums = [3, 4, 5, 6, 1, 2]

// Explanation:
// rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
// rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]
// Example 2:
// Input: nums = [3, 4, 1, 5, 3, -5], k = 8
// Output: nums = [1, 5, 3, -5, 3, 4]

// Explanation:
// rotate 1 step to the left: [4, 1, 5, 3, -5, 3]
// rotate 2 steps to the left: [1, 5, 3, -5, 3, 4]
// rotate 3 steps to the left: [5, 3, -5, 3, 4, 1]
// rotate 4 steps to the left: [3, -5, 3, 4, 1, 5]
// rotate 5 steps to the left: [-5, 3, 4, 1, 5, 3]
// rotate 6 steps to the left: [3, 4, 1, 5, 3, -5]
// rotate 7 steps to the left: [4, 1, 5, 3, -5, 3]
// rotate 8 steps to the left: [1, 5, 3, -5, 3, 4]

void leftRotateByK(vector<int> &nums, int target){
    if(target > nums.size()){
        target = target % nums.size();
    }

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end()-target);
    reverse(nums.end()-target, nums.end());
}

int main(){
    vector<int> nums = {3, 4, 1, 5, 3, -5};
    int target = 8;

    for(auto a : nums){
        cout<<a<<" ";
    }
    cout<<endl;

    leftRotateByK(nums, target);

    for(auto a : nums){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}

// note:- 
// - if target is bigger then size of vector then do (target % nums.size()) and store it to the target it will solve the problem