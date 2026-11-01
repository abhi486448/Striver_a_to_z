#include<bits/stdc++.h>
using namespace std;

// my solution
vector<int> findRepeatingAndMissing(vector<int> &nums){
    unordered_map<int, int> mpp;
    int el=0;
    int sum = 0;
    int natural = 0;
    for(int i=0; i<nums.size(); i++){
        mpp[nums[i]]++;
        sum += nums[i];
        natural += i+1;
    }
    for(auto m:mpp){
        if(m.second == 2){
            el = m.first;
            break;
        }
    }
    sum-=el;
    natural-=sum;
    return {el, natural};
}

// best - bit manupulation
vector<int> betterFindRepeatingAndMissing(vector<int> &nums){
    int xr = 0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        xr = xr^nums[i];
        xr = xr^(i+1);
    }
    int bitNum = 0;
    while(1){
        if((xr & (1<<bitNum)) != 0){
            break;
        }
        bitNum++;
    }
    int zero=0;
    int one=0;
    for(int i=0; i<n; i++){
        if((nums[i] & (1<<bitNum)) != 0){
            one = one^nums[i];
        } else {
            zero = zero^nums[i];
        }

        if((i+1 & (1<<bitNum)) != 0){
            one = one^(i+1);
        } else {
            zero = zero^(i+1);
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i]==zero){
            cnt++;
        }
    }
    if(cnt==2) return {zero, one};
    return {one, zero};
}

int main(){
    vector<int> nums={3,5,4,1,1};
    // vector<int> ans = findRepeatingAndMissing(nums);
    vector<int> ans = betterFindRepeatingAndMissing(nums);
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}