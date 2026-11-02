#include<bits/stdc++.h>
using namespace std;

// brut
int bruteMaxProduct(vector<int> &nums){
    int maxMult = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        int mult = 1;
        for(int j=i; j<nums.size(); j++){
            mult = mult*nums[j];
            maxMult = max(mult, maxMult);
        }

    }
    return maxMult;
}
// complexcity
// time = O(N*N);

// better
int betterMaxProduct(vector<int> &nums){
    int maxMult = INT_MIN;
    int pri=1, suff = 1;
    int n=nums.size();
    for(int i=0; i<n; i++){
        if(pri==0) pri=1;
        if(suff==0) suff=1;
        pri *= nums[i];
        suff *= nums[n-i-1];
        maxMult = max(maxMult, max(pri, suff));
    }
    return maxMult;
}
// complexcity
// time = O(n);
// space =O(1);


int main(){
    vector<int> nums={-5, 0, -2};
    // cout<<bruteMaxProduct(nums)<<endl;
    cout<<betterMaxProduct(nums)<<endl;

    return 0;
}