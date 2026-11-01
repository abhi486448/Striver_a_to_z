#include<bits/stdc++.h>
using namespace std;

// 375. Rearrange array elements by sign
// Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are met:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Example 1:
// Input : nums = [2, 4, 5, -1, -3, -4]
// Output : [2, -1, 4, -3, 5, -4]
// Explanation:
// The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions
// Example 2:
// Input : nums = [1, -1, -3, -4, 2, 3]
// Output : [1, -1, 2, -3, 3, -4]
// Explanation:
// The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions
// Example 3:
// Input: nums = [-4, 4, -4, 4, -4, 4]
// Output:
// [4, -4, 4, -4, 4, -4]
// Constraints:
// 2 <= nums.length <= 105
// 1 <= | nums[i] | <= 104
// nums.length is an even number.
// Number of positive and negative numbers are equal.

vector<int> rearrangeArray(vector<int> &nums){
    int n = nums.size();
    vector<int> result(n, 0);

    int positive = 0;
    int negative = 1;

    for(auto a:nums){
        if(a>0){
            result[positive] = a;
            positive+=2;
        } else {
            result[negative] = a;
            negative+=2;
        }
    }
    return result;
}

int main(){
    vector<int> nums={2, 4, 5, -1, -3, -4};
    vector<int> result = rearrangeArray(nums);

    for(auto a:result){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
// note:-
// - don't trape under pointers think beond it;