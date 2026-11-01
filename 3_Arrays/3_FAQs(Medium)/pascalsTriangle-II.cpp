#include<bits/stdc++.h>
using namespace std;

vector<int> pascalsTriangle(int row){
    vector<vector<int>> ans;

    for(int i=0; i<row; i++){
        vector<int> temp(i+1, 1);
        for(int j=1; j<i; j++){
            temp[j] = ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(temp);
    }
    return ans[row-1];
}

int main(){
    vector<int> ans;
    int row = 4;

    ans = pascalsTriangle(row);
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}