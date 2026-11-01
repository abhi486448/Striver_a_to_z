#include<bits/stdc++.h>
using namespace std;

// 36. Sort an array of 0's 1's and 2's
// Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.

// The sorting must be done in-place, without making a copy of the original array.

// Example 1:
// Input: nums = [1, 0, 2, 1, 0]
// Output: [0, 0, 1, 1, 2]
// Explanation:
// The nums array in sorted order has 2 zeroes, 2 ones and 1 two
// Example 2:
// Input: nums = [0, 0, 1, 1, 1]
// Output: [0, 0, 1, 1, 1]
// Explanation:
// The nums array in sorted order has 2 zeroes, 3 ones and zero twos
// Example 3:
// Input: nums = [1, 1, 2, 2, 1]
// Output:
// [1, 1, 1, 2, 2]
// Constraints:
// 1 <= nums.length <= 105
// nums consists of 0, 1 and 2 only.

void sortArray(vector<int> &nums){
    int low=0;
    int mid=0;
    int high=nums.size()-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if(nums[mid]==1){
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main(){
    vector<int> nums = {2,2,1,2,0,1,0};
    sortArray(nums);
    for(auto a:nums){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}