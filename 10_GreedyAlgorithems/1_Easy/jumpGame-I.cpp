#include<bits/stdc++.h>
using namespace std;

bool jumpGame(vector<int> &nums){
    int maxJump = 0;
    int n = nums.size();
    for(int i=0; i<=n-1; i++){
        if(maxJump<i) return false;
        maxJump = max(maxJump, i+nums[i]);
        if(maxJump>=n-1) return true;
    }
    return true;
}

int main(){
    vector<int> nums={2, 3, 1, 1, 4};
    cout<<jumpGame(nums)<<endl;
    return 0;
}