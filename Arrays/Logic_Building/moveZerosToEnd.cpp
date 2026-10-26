#include<bits/stdc++.h>
using namespace std;

// 248. Move Zeros to End
// Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.

// This must be done in place, without making a copy of the array.

// Example 1:
// Input: nums = [0, 1, 4, 0, 5, 2]
// Output: [1, 4, 5, 2, 0, 0]
// Explanation:
// Both the zeroes are moved to the end and the order of the other elements stay the same
// Example 2:
// Input: nums = [0, 0, 0, 1, 3, -2]
// Output: [1, 3, -2, 0, 0, 0]
// Explanation:
// All 3 zeroes are moved to the end and the order of the other elements stay the same

void moveZero(vector<int> &nums){
    int p2 = 0;
    int temp = 0;

    if(nums.size()>=1){
        for(int p1 = 0; p1<nums.size(); p1++){
            if(nums[p2]!=0){
                p2++;
            }

            if(nums[p1]==0){
                continue;
            } else if(nums[p1]!=0){
                temp = nums[p1];
                nums[p1]= nums[p2];
                nums[p2]= temp;
                p2++;
            }
        }
    }

}

int main(){
    vector<int> nums = {0, 1, 4, 0, 5, 2};

    for(auto a: nums){
        cout<<a<<" ";
    }
    cout<<endl;

    moveZero(nums);

    for(auto a: nums){
        cout<<a<<" ";
    }
    cout<<endl;

    return 0;
}
// note:-
// -- make sure the size of array must be grater then 1
// complexcity = O(N)