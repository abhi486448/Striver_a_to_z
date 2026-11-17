#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums){
    int n = nums.size();
    int totalsub = 1<<n;

    vector<vector<int> > ans(totalsub);
    for(int i=0; i<totalsub; i++){
        vector<int> sub;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                sub.push_back(nums[j]);
            }
        }
        ans[i] = sub;
    }
    return ans;
}

int main(){
    vector<int> nums={1, 2, 3};
    vector<vector<int>> ans = powerSet(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}