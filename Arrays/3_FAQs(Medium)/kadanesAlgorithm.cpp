#include<bits/stdc++.h>
using namespace std;

// 12. Kadane's Algorithm
// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [2, 3, 5, -2, 7, -4]
// Output: 15
// Explanation:
// The subarray from index 0 to index 4 has the largest sum = 15
// Example 2:
// Input: nums = [-2, -3, -7, -2, -10, -4]
// Output: -2
// Explanation:
// The element on index 0 or index 3 make up the largest sum when taken as a subarray
// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// better
int betterMaxSumOfSubArray(vector<int> &nums){
    int maxsum=INT_MIN;
    for(int i=0; i<nums.size(); i++){
        int sum=0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}
// complexcity
// time = O(n*n)
// space = O(1)

// best
int kadanesAlgorithm(vector<int> &nums){
    int maxSum = INT_MIN;
    int sum=0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum>maxSum){
            maxSum = sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}
// complexcity 
// time = O(n)
// space = O(1)

int main(){
    vector<int> nums={2, 3, 5, -2, 7, -4};
    // cout<<betterMaxSumOfSubArray(nums)<<endl;
    cout<<kadanesAlgorithm(nums)<<endl;
    return 0;
}