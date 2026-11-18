#include<bits/stdc++.h>
using namespace std;

void targetSub(int p,vector<int> &sub,vector<int> &nums,vector<vector<int>> &ans,int target){
    if(target==0){
        ans.push_back(sub);
        return;
    }

    for(int i=p; i<nums.size(); i++){
        if(i>p && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;

        sub.push_back(nums[i]);
        targetSub(i+1, sub, nums, ans, target-nums[i]);
        sub.pop_back();
    }
}
// complexcity
// time = O(2^n * n);
// space = O(n + k*x)

void printSub(vector<vector<int>> &ans){
    for(auto a:ans){
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> nums={2, 1, 2, 7, 6, 1, 5};
    sort(nums.begin(), nums.end());
    int target=8;
    vector<vector<int>> ans;
    vector<int> sub;
    targetSub(0, sub, nums, ans, target);
    printSub(ans);
    return 0;
}