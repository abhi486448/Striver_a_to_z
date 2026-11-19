#include<bits/stdc++.h>
using namespace std;

void subString(string &digits,map<char, string> &mpp,vector<string> &ans,string &s, int i){
    if(s.size()==digits.size()){
        ans.push_back(s);
        return;
    }

    for(int j=0; j<mpp[digits[i]].size(); j++){
        s.push_back(mpp[digits[i]][j]);
        subString(digits, mpp, ans, s, i+1);
        s.pop_back();
    }
}

void printString(vector<string> &ans){
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
}

int main(){
    string digits="34";
    map<char, string> mpp;
    mpp['2']="abc";
    mpp['3']="def";
    mpp['4']="ghi";
    mpp['5']="jkl";
    mpp['6']="mno";
    mpp['7']="pqrs";
    mpp['8']="tuv";
    mpp['9']="wxyz";
    vector<string> ans;
    string s;
    subString(digits, mpp, ans, s, 0);
    printString(ans);
    return 0;
}