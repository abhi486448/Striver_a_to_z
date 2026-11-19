#include<bits/stdc++.h>
using namespace std;

void subSet(int p,int sum,vector<int> &ans,vector<int> &nums){
    if(p==nums.size()){
        ans.push_back(sum);
        return;
    }

    sum+=nums[p];
    subSet(p+1, sum, ans, nums);
    sum-=nums[p];

    subSet(p+1, sum, ans, nums);
}

void printSum(vector<int> &ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums={2, 3};
    vector<int> ans;
    int sum=0;

    subSet(0, sum, ans, nums);
    printSum(ans);
    return 0;
}