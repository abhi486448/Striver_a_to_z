#include<bits/stdc++.h>
using namespace std;

int jumpGame(vector<int> &nums){
    int l=0;
    int r=0;
    int jump=0;
    while(r<nums.size()-1){
        int far = 0;
        for(int i=l; i<=r; i++){
            far = max(far, i+nums[i]);
        }
        l=r+1;
        r = far;
        jump++;
    }
    return jump;
}

int main(){
    vector<int> nums={2,3,1,1,4};
    cout<<jumpGame(nums)<<endl;
    return 0;
}