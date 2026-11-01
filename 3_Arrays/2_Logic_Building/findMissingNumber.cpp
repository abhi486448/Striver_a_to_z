#include<bits/stdc++.h>
using namespace std;

// 116. Find missing number
// Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.

// Example 1:
// Input: nums = [0, 2, 3, 1, 4]
// Output: 5
// Explanation:
// nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]
// Example 2:
// Input: nums = [0, 1, 2, 4, 5, 6]
// Output: 3
// Explanation:
// nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]
// Example 3:
// Input: nums = [1, 3, 6, 4, 2, 5]
// Output:
// 0

int findMissing(vector<int> &nums){
    int n = nums.size();
    int sum = (n*(n+1))/2;

    for(auto a:nums){
        sum-=a;
    }

    return sum;
}

int main(){
    vector<int> nums={0, 2, 3, 1, 4};

    for(auto a:nums){
        cout<<a<<" ";
    }
    cout<<endl;

    cout<<findMissing(nums)<<endl;

    return 0;
}

// note:-
// - only return sum no need for any condition everything cover in it
// - use (n*(n+1))/2