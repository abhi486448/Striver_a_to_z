#include<bits/stdc++.h>
using namespace std;

// 213. Maximum Consecutive Ones
// Given a binary array nums, return the maximum number of consecutive 1s in the array.

// A binary array is an array that contains only 0s and 1s.

// Example 1:
// Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
// Output: 3
// Explanation:
// The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s
// Example 2:
// Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
// Output: 0
// Explanation:
// No 1s are present in nums, thus we return 0

int maxConsecutive(vector<int> nums){
    int count = 0;
    int temp = 0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 1){
            temp++;
            if(i == nums.size()-1 && temp>count){
                count = temp;
                temp = 0;
            }
        } else if(nums[i] == 0){
            if(temp>count){
                count = temp;
                temp = 0;
            } else {
                temp = 0;
            }
        }
    }

    return count;
}

int main(){
    vector<int> nums = {0,0,0,0};
    cout<<maxConsecutive(nums)<<endl;
    return 0;
}

// points to note:-
// - check if the given array is empty
// - check if the given array only contain 0s
// - update count in the case of lase element is 1 and temp is > then count
