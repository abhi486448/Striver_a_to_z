#include<bits/stdc++.h>
using namespace std;

int brutCountSubarraySum(vector<int> &nums,int k){
    int count =0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i; j<nums.size(); j++){
            int sum = 0;
            for(int p=i; p<=j; p++){
                sum+=nums[p];
            }
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}
// complexcity
// time = O(n^3);

// better
int betterCountSubarraySum(vector<int> &nums,int k){
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        int sum =0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}
// complexcity
// time = O(n^2);

// optimal
int optimalCountSubarraySum(vector<int> &nums,int k){
    int count =0;
    int sum = 0;
    unordered_map<int, int> mpp;
    mpp[sum] = 1;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        int rem = sum-k;
        count += mpp[rem];
        mpp[sum]+= 1; 
    }
    return count;
}
// complexcity
// time = O(n);
// space = O(n);

int main(){
    vector<int> nums={1, 1, 1};
    int k = 2;
    // cout<<brutCountSubarraySum(nums, k)<<endl;
    // cout<<betterCountSubarraySum(nums, k)<<endl;
    cout<<optimalCountSubarraySum(nums, k)<<endl;
    return 0;
}