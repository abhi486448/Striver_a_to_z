#include<bits/stdc++.h>
using namespace std;

int countSub(int p,int sum,vector<int> &nums,int k){
    if(p>=nums.size()){
        if(sum>k) return 0;
        if(sum==k){
            return 1;
        }else{
            return 0;
        }
    }

    sum+=nums[p];
    int left= countSub(p+1, sum, nums, k);

    sum-=nums[p];
    int right = countSub(p+1, sum, nums, k);

    return left+right;
}
//complexcity
// time = O(2^n);

int main(){
    vector<int> nums={4, 9, 2, 5, 1};
    int k=10;
    
    int sum=0;
    cout<<countSub(0, sum, nums, k)<<endl;
    return 0;
}