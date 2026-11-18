#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int> &temp){
    for(auto it:temp){
        cout<<it<<" ";
    }
    cout<<endl;
}

void printSub(int p,vector<int> &temp, vector<int> &nums){
    if(p>=nums.size()){
        printArr(temp);
        return;
    }

    temp.push_back(nums[p]);
    printSub(p+1, temp, nums);
    temp.pop_back();
    printSub(p+1, temp, nums);
}

// complexcity
// time = O(2^n * n)
// space = O(n)

int main(){
    vector<int> nums={3,1,2};
    vector<int> temp;
    printSub(0, temp, nums);
    return 0;
}