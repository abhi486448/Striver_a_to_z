#include<bits/stdc++.h>
using namespace std;

// brut
vector<int> brutLeaders(vector<int> &nums){
    bool leader = true;
    vector<int> result;

    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[j]>nums[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            result.push_back(nums[i]);
        }
        leader=true;
    }

    return result;
}
// complexcity 
// time O(N*N)
// space O(N)

// best
vector<int> leaders(vector<int>& nums) {
    vector<int> result;
    if(nums.empty()) return result;

    int large = nums.back();
    result.push_back(large);

    for(int i=nums.size()-2; i>=0; i--){
        if(nums[i]>large){
            large = nums[i];
            result.push_back(large);
        }
    }

    reverse(result.begin(), result.end());
    return result;
}
// complexcity
// time O(N);
// space O(N)

int main(){
    vector<int> nums={1, 2, 5, 3, 1, 2};
    for(auto a:nums){
        cout<<a<<" ";
    }
    cout<<endl;
    // vector<int> result = leaders(nums);
    vector<int> result = brutLeaders(nums);
    for(auto a:result){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}