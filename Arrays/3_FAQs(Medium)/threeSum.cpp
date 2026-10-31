#include<bits/stdc++.h>
using namespace std;

// 21. 3 Sum
// Given an integer array nums. Return all triplets such that:

// i != j, i != k, and j != k
// nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.

// Example 1:
// Input: nums = [2, -2, 0, 3, -3, 5]
// Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]
// Explanation:
// nums[1] + nums[2] + nums[0] = 0
// nums[4] + nums[1] + nums[5] = 0
// nums[4] + nums[2] + nums[3] = 0
// Example 2:
// Input: nums = [2, -1, -1, 3, -1]
// Output: [[-1, -1, 2]]
// Explanation:
// nums[1] + nums[2] + nums[0] = 0
// Note that we have used two -1s as they are separate elements with different indexes
// But we have not used the -1 at index 4 as that would create a duplicate triplet
// Example 3:
// Input: nums = [8, -6, 5, 4]
// (Give answer with the output and triplets sorted in ascending order)
// Output:
// []
// Constraints:
// 1 <= nums.length <= 3000
// -104 <= nums[i] <= 104

// brut
vector<vector<int>> brutThreeSum(vector<int> &nums){
    set<vector<int>> st;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp;
                    temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// complexcity
// time = O(n*m*o) + O(n log n) = n^3;
// space = O(n) + O(n)

// better
vector<vector<int>> betterThreeSum(vector<int> &nums){
    set<vector<int> > st;
    for(int i=0; i<nums.size(); i++){
        set<int> hashmap;
        for(int j=i+1; j<nums.size(); j++){
            int third = -(nums[i]+nums[j]);
            if(hashmap.find(third)!=hashmap.end()){
                vector<int> temp;
                temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashmap.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// complexcity
// time = n*n*log m
// space = n + n

// best
vector<vector<int>> bestThreeSum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n= nums.size();

    for(int i=0; i<n; i++){
        if(i>0 && nums[i]== nums[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            } else if(sum>0){
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
        
    }
    return ans;
}
// complexcity
// time = n^2 + n log n
// space = m

int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    // vector<vector<int>> ans=brutThreeSum(nums);
    // vector<vector<int>> ans=betterThreeSum(nums);
    vector<vector<int>> ans=bestThreeSum(nums);

    for(auto a:ans){
        for(auto b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    return 0;
}