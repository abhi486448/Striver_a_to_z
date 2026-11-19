#include<bits/stdc++.h>
using namespace std;

void subSet(int p,vector<int> &sub,vector<vector<int>> &ans,vector<int> &nums){
    ans.push_back(sub);

    for(int i=p; i<nums.size(); i++){
        if(i>p && nums[i]==nums[i-1]) continue;

        sub.push_back(nums[i]);
        subSet(i+1, sub, ans, nums);
        sub.pop_back();
    }
}

void printSub(vector<vector<int>> &ans){
    for(auto a:ans){
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> nums={1, 2, 2};
    vector<vector<int>> ans;
    vector<int> sub;
    subSet(0, sub, ans, nums);
    printSub(ans);
    return 0;
}