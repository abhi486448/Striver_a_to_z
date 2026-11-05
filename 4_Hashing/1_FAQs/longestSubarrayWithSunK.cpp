#include<bits/stdc++.h>
using namespace std;

// brut
int longestSumK(vector<int> &nums, int k){
    int maxCnt = 0;
    for(int i=0; i<nums.size(); i++){
        int sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            if(sum == k){
                maxCnt = max(maxCnt, j-i+1);
            }

        }
    }
    return maxCnt;
}
// complexcity
// time = O(n*n);

// better
int betterLongestSumK(vector<int> &nums,int k){
    unordered_map<int, int> mpp;
    int sum = 0;
    int maxLen = 0;
    for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
        if(sum==k){
            maxLen = max(maxLen, i+1);
        }
        int rem = sum-k;
        if(mpp.find(rem)!=mpp.end()){
            int len = i-mpp[rem];
            maxLen = max(maxLen, len);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum] = i;
        }
    }
    return maxLen;
}
// complexcity
// time = O(n) in verse case O(n*n)
// if we use ordered map O(n log n)
// space = O(n)

// optimal // only if there is no negative values
int optimalLongestSumK(vector<int> &nums,int k){
    int n = nums.size();
    int left = 0;
    int right = 0;
    int maxLan = 0;
    int sum = nums[0];
    while(right<n){
        while(left<=right && sum>k){
            sum -= nums[left];
            left++;
        }
        if(sum==k){
            maxLan = max(maxLan, right-left+1);
        }
        right++;
        if(sum<k){
            sum += nums[right];
        }
    }
    return maxLan;
}
// complexcity
// time = O(n);

int main(){
    vector<int> nums={2,0,0,0,3};
    int k = 3;
    // cout<<longestSumK(nums, k)<<endl;
    // cout<<betterLongestSumK(nums, k)<<endl;
    cout<<optimalLongestSumK(nums, k)<<endl;
    return 0;
}