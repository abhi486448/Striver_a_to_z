#include<bits/stdc++.h>
using namespace std;

bool printSub(int p,int sum,vector<int> &nums,int k){
    if(p>=nums.size()){
        if(sum==k){
            return true;
        }else{
            return false;
        }
    }

    sum+=nums[p];
    if(printSub(p+1, sum, nums, k)==true) return true;

    sum-=nums[p];
    if(printSub(p+1, sum, nums, k)==true) return true;

    return false;
}

int main(){
    vector<int> nums={4, 3, 9, 2};
    int k=10;
    int sum=0;
    bool check = printSub(0, sum, nums, k);
    if(check){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}