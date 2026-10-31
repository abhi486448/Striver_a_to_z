#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &nums){
    if(nums.empty()) return {};
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int count =1;
    int n = nums.size()/3;
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1]){
            count++;
        } else {
            if(count>n){
                ans.push_back(nums[i-1]);
            }
            count = 1;
        }
    }

    if(count>n){
        ans.push_back(nums.back());
    }
    return ans;
}

int main(){
    vector<int> nums={1, 2, 1, 1, 3, 2, 2};
    vector<int> ans = majorityElementII(nums);
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}