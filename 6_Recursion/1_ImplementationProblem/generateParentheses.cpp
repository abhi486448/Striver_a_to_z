#include<bits/stdc++.h>
using namespace std;

void genPar(string &temp,int n,int left,int right,vector<string> &ans){
    if(left==n && right==n){
        ans.push_back(temp);
        return;
    }
    if(left<n){
        temp.push_back('(');
        genPar(temp, n, left+1, right, ans);
        temp.pop_back();
    }
    if(right<left){
        temp.push_back(')');
        genPar(temp, n, left, right+1, ans);
        temp.pop_back();
    }
}
// complexcity
// time = O(n lon n);
// space = O(1);

int main(){
    vector<string> ans;
    string temp;
    int n = 2;
    genPar(temp, n, 0, 0, ans);
    for(auto s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}