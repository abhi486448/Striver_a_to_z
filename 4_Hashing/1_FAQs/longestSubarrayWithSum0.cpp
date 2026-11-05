#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums){
    unordered_map<int, int> mpp;
    int maxLan = 0;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum==0){
            maxLan = max(maxLan, i+1);
        }
        int rem = sum-0;
        if(mpp.find(rem)!=mpp.end()){
            int lan = i-mpp[rem];
            maxLan = max(maxLan, lan);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxLan;
}

int main(){
    vector<int> nums={15, -2, 2, -8, 1, 7, 10, 23};
    cout<<longestSubarray(nums)<<endl;
    return 0;
}