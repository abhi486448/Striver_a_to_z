#include<bits/stdc++.h>
using namespace std;

// 83. Majority Element-I
// Given an integer array nums of size n, return the majority element of the array.

// The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

// Example 1:
// Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
// Output: 7
// Explanation:
// The number 7 appears 5 times in the 9 sized array
// Example 2:
// Input: nums = [1, 1, 1, 2, 1, 2]
// Output: 1
// Explanation:
// The number 1 appears 4 times in the 6 sized array
// Example 3:
// Input: nums = [-1, -1, -1, -1]
// Output:
// -1
// Constraints:
// n == nums.length.
// 1 <= n <= 105
// -104 <= nums[i] <= 104
// One value appears more than n/2 times.

// brute
int brutMajorityElement(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        int count =0;
        for(int j=i; j<nums.size(); j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }

        if(count > nums.size()/2){
            return nums[i];
        }
    }
    return -1;
}
// complexcity O(n*n)

// better
int betterMajorityElement(vector<int> &nums){
    unordered_map<int, int> ump;

    for(auto a:nums){
        ump[a]++;
    }

    for(auto it:ump){
        if(it.second>nums.size()/2){
            return it.first;
        }
    }
    return -1;
}
// complexcity
// avg case O(n)
// worse case O(n*n)

// best
// with help of boyer- mooor algorithem
int bestMajorityElement(vector<int> &nums){
    int el = nums[0];
    int count =1;
    for(int i=1; i<nums.size(); i++){
        if(count ==0){
            el = nums[i];
            count = 1;
        } else if(el == nums[i]){
            count++;
        } else {
            count--;
        }
    }

    if(count>0){
        int c=0;
        for(int i=0; i<nums.size(); i++){
            if(el == nums[i]){
                c++;
            }
        }
        if(c>nums.size()/2){
            return el;
        }
    }
    return -1;
}

int main (){
    vector<int> nums={7, 0, 0, 1, 7, 7, 2, 7, 7};
    // cout<<brutMajorityElement(nums)<<endl;
    // cout<<betterMajorityElement(nums)<<endl;
    cout<<bestMajorityElement(nums)<<endl;
    return 0;
}

// note:- 
// - index based update count will take too much space so dont use it
// - use hase or moore algorithem