#include<bits/stdc++.h>
using namespace std;

void printSub(int p,int sum, vector<int> &sub,vector<int> &nums, int s){
    if(p>=nums.size()){
        if(sum==s){
            for(auto it:sub){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    sub.push_back(nums[p]);
    sum+=nums[p];
    printSub(p+1, sum, sub, nums, s);

    sum-=nums[p];
    sub.pop_back();
    printSub(p+1, sum, sub, nums, s);
}

int main(){
    vector<int> nums={1,2,1};
    int s=2;
    vector<int> sub;
    int sum =0;
    printSub(0,sum, sub, nums, s);
    return 0; 
}