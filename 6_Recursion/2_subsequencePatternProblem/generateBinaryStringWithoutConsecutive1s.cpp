#include<bits/stdc++.h>
using namespace std;

void stringSub(int p,string &s,vector<string> &ans,int n){
    if(p>=n){
        ans.push_back(s);
        return;
    }

    if(s.empty() || s.back()=='0'){
        s.push_back('0');
        stringSub(p+1, s, ans, n);
        s.pop_back();

        s.push_back('1');
        stringSub(p+1, s, ans, n);
        s.pop_back();
    }else{
        if(s.back()=='1'){
            s.push_back('0');
            stringSub(p+1, s, ans, n);
            s.pop_back();
        }
    }
}

void printAns(vector<string> &ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 3;
    vector<string> ans;
    string s;
    stringSub(0, s, ans, n);
    printAns(ans);
    return 0;
}