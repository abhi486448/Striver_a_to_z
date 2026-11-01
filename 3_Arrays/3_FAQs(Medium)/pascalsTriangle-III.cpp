#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalsTriangel(int r){
    vector<vector<int>> ans;
    for(int i=0; i<r; i++){
        vector<int> row(i+1, 1);
        for(int j=1; j<i; j++){
            row[j] = ans[i-1][j-1]+ans[i-1][j];
        }
        ans.push_back(row);
    }
    return ans;
}

int main(){
    int row = 4;
    vector<vector<int>> ans;

    ans = pascalsTriangel(row);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}