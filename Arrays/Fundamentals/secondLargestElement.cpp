#include<bits/stdc++.h>
using namespace std;

// 695. Second Largest Element
// Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

// Example 1:
// Input: nums = [8, 8, 7, 6, 5]
// Output: 7
// Explanation:
// The largest value in nums is 8, the second largest is 7
// Example 2:
// Input: nums = [10, 10, 10, 10, 10]
// Output: -1
// Explanation:
// The only value in nums is 10, so there is no second largest value, thus -1 is returned

int secLargElm(vector<int> nums){
    int larg = INT_MIN;
    int SecLarg = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]>larg){
            SecLarg = larg;
            larg = nums[i];
        }
        if(nums[i]<larg && nums[i]>SecLarg){
            SecLarg = nums[i];
        }

    }

    if(SecLarg == INT_MIN){
        return -1;
    } else {
        return SecLarg;
    }
}

int main(){

    vector<int> nums = {10, 10, 10, 10, 10};

    cout<<secLargElm(nums)<<endl;

    return 0;
}