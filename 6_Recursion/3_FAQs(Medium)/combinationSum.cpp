#include<bits/stdc++.h>
using namespace std;

void targetSub(int p,vector<int> &sub,vector<int> &nums,vector<vector<int>> &ans,int target){
    if(p==nums.size()){
        if(target==0){
            ans.push_back(sub);
        }
        return;
    }

    if(nums[p]<=target){
        sub.push_back(nums[p]);
        targetSub(p, sub, nums, ans, target-nums[p]);
        sub.pop_back();
    }
    targetSub(p+1, sub, nums, ans, target);
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
    vector<int> nums={2, 3, 5, 4};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> sub;

    targetSub(0, sub, nums, ans, target);
    printSub(ans);
    return 0;
}