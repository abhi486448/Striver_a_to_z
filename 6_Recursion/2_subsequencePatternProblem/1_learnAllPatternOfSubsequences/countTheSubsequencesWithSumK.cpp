#include<bits/stdc++.h>
using namespace std;

int countSub(int p,int sum,vector<int> &nums, int s){
    if(p>=nums.size()){
        if(sum==s){
            return 1;
        }
        else return 0;
    }

    sum+=nums[p];
    int left = countSub(p+1, sum, nums, s);

    sum-=nums[p];
    int right = countSub(p+1, sum, nums, s);

    return left+right;
}
// complexcity
// time = O(2^n);

int main(){
    vector<int> nums={1,2,1};
    int s=2;
    int sum = 0;
    cout<<countSub(0, sum, nums, s)<<endl;
    return 0;
}