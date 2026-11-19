#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end){
    while(start<end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void paliString(int p,string &s,vector<string> &sub,vector<vector<string>> &ans){
    if(p==s.size()){
        ans.push_back(sub);
        return;
    }

    for(int i=p; i<s.size(); i++){
        if(isPalindrome(s, p, i)){
            sub.push_back(s.substr(p, i-p+1));
            paliString(i+1, s, sub, ans);
            sub.pop_back();
        }
    }
}

void printSub(vector<vector<string>> &ans){
    for(auto a:ans){
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main(){
    string s="aabaa";
    vector<vector<string>> ans;
    vector<string> sub;
    paliString(0, s, sub, ans);
    printSub(ans);
    return 0;
}