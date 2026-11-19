#include<bits/stdc++.h>
using namespace std;

void subSet(int k,int n,int sum,vector<int> &sub,vector<vector<int>> &ans,int i){
    if(sub.size()==k){
        if(sum==n){
            ans.push_back(sub);
        }
        return;
    }
    if(i==10){
        return;
    }

    sub.push_back(i);
    sum+=i;
    subSet(k, n, sum, sub, ans, i+1);
    sum-=i;
    sub.pop_back();

    subSet(k, n, sum, sub, ans, i+1);
}

void printSub(vector<vector<int>> &ans){
    for(auto a:ans){
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int k=3, n=9;
    vector<vector<int>> ans;
    vector<int> sub;
    subSet(k, n, 0, sub, ans, 1);
    printSub(ans);
    return 0;
}