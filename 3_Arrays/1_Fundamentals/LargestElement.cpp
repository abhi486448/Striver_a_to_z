#include<bits/stdc++.h>
using namespace std;

// 702. Largest Element
// Given an array of integers nums, return the value of the largest element in the array

// Example 1:
// Input: nums = [3, 3, 6, 1]
// Output: 6
// Explanation: The largest element in array is 6
// Example 2:
// Input: nums = [3, 3, 0, 99, -40]
// Output: 99
// Explanation: The largest element in array is 99

int largestElement(vector<int> nums){
    int large = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>large){
            large = nums[i];
        }
    }
    return large;
}

int main (){
    vector<int> nums = {3, 3, 6, 1};

    cout<<largestElement(nums)<<endl;

    return 0;
}