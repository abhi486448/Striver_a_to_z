#include<bits/stdc++.h>
using namespace std;

bool printSub(int p,int sum, vector<int> &sub,vector<int> &nums, int s){
    if(p>=nums.size()){
        if(sum==s){
            for(auto it:sub){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }else{
            return false;
        }
    }

    sub.push_back(nums[p]);
    sum+=nums[p];
    if(printSub(p+1, sum, sub, nums, s)==true) return true;

    sum-=nums[p];
    sub.pop_back();
    if(printSub(p+1, sum, sub, nums, s)==true) return true;

    return false;
}

int main(){
    vector<int> nums={1,2,1};
    int s=2;
    vector<int> sub;
    int sum =0;
    printSub(0,sum, sub, nums, s);
    return 0; 
}