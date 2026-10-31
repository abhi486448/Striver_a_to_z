#include<bits/stdc++.h>
using namespace std;

// 169. 4 Sum
// Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// a, b, c, d are all distinct valid indices of nums.
// nums[a] + nums[b] + nums[c] + nums[d] == target.
// Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.

// Example 1:
// Input: nums = [1, -2, 3, 5, 7, 9], target = 7
// Output: [[-2, 1, 3, 5]]
// Explanation:
// nums[1] + nums[0] + nums[2] + nums[3] = 7
// Example 2:
// Input: nums = [7, -7, 1, 2, 14, 3], target = 9
// Output: []
// Explanation:
// No quadruplets are present which add upto 9
// Constraints:
// 1 <= nums.length <= 200
// -104 <= nums[i] <= 104
// -104 <= target <= 104

vector<vector<int> > fourSum(vector<int> &nums,int target){
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;

    for(int i=0; i<nums.size(); i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        while(j<nums.size()){
            if(j>i+1 && nums[j]==nums[j-1]){
                j++;
                continue;
            }
            int k=j+1;
            int l=nums.size()-1;
            while(k<l){
                long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target){
                    k++;
                } else if(sum>target){
                    l--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> nums={1, -2, 3, 5, 7, 9};
    int target = 7;
    vector<vector<int>> ans = fourSum(nums, target);

    for(auto a:ans){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}