#include<bits/stdc++.h>
using namespace std;

// better
int betterCountSubarrayXor(vector<int> &nums,int k){
    int count =0;
    for(int i=0; i<nums.size(); i++){
        int xr = 0;
        for(int j=i; j<nums.size(); j++){
            xr ^= nums[j];
            if(xr == k){
                count++;
            }
        }
    }
    return count;
}
// complexcity
// time = O(n*n);

// optimal
int optimalCountSubarrayXor(vector<int> &nums,int k){
    int count =0;
    int xr =0;
    unordered_map<int, int> mpp;
    mpp[xr] =1;
    for(int i=0; i<nums.size(); i++){
        xr ^= nums[i];
        int rem = xr^k;
        count += mpp[rem];
        mpp[xr] +=1;
    }
    return count;
}
// complexcity
// time = O(n);
// space = O(n);

int main(){
    vector<int> nums={4, 2, 2, 6, 4};
    int k = 6;
    // cout<<betterCountSubarrayXor(nums, k)<<endl;
    cout<<optimalCountSubarrayXor(nums, k)<<endl;
    return 0;
}