#include<bits/stdc++.h>
using namespace std;

// 832. Left Rotate Array by One
// Given an integer array nums, rotate the array to the left by one.

// Note: There is no need to return anything, just modify the given array.
// Example 1:
// Input: nums = [1, 2, 3, 4, 5]
// Output: [2, 3, 4, 5, 1]
// Explanation:
// Initially, nums = [1, 2, 3, 4, 5]
// Rotating once to left -> nums = [2, 3, 4, 5, 1]
// Example 2:
// Input: nums = [-1, 0, 3, 6]
// Output: [0, 3, 6, -1]
// Explanation:
// Initially, nums = [-1, 0, 3, 6]
// Rotating once to left -> nums = [0, 3, 6, -1]

void leftRotate(vector<int> &nums){
    int k = 1;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end()-k);
    reverse(nums.end()-k, nums.end());
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};

    for(auto a : nums){
        cout<<a<<" ";
    }
    cout<<endl;

    leftRotate(nums);

    for(auto a : nums){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}

// complexcity is
// O(N)