#include<bits/stdc++.h>
using namespace std;

int pascalsTriangle(int c, int r){
    vector<vector<int>> ans;
    vector<int> temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<=i; j++){
            if((i==0 && j==0) || j==0 || j==i){
                temp.push_back(1);
            }else {
                int sum = 0;
                sum = ans[i-1][j-1] + ans[i-1][j];
                temp.push_back(sum);
            }
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans[r-1][c-1];
}

int main(){
    int r=6;
    int c=2;
    cout<<pascalsTriangle(c, r)<<endl;
    return 0;
}