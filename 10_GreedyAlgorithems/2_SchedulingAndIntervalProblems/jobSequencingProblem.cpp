#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[2]>b[2];
}

vector<int> jobSequencingProblem(vector<vector<int>> &jobs){
    sort(jobs.begin(), jobs.end(), compare);
    int maxDedline = -1;
    for(int i=0; i<jobs.size(); i++){
        if(jobs[i][1]>maxDedline){
            maxDedline = jobs[i][1];
        }
    }

    vector<int> st(maxDedline+1, -1);
    int noj = 0;
    int maxProfit = 0;
    for(int i=0; i<jobs.size(); i++){
        for(int j = jobs[i][1]; j>0; j--){
            if(st[j]==-1){
                noj++;
                st[j] = jobs[i][0];
                maxProfit += jobs[i][2];
                break;
            }
        }
    }

    return {noj, maxProfit};
}

int main(){
    vector<vector<int>> jobs={{1, 4, 20},{2, 1, 10},{3, 1, 40},{4, 1, 30}};
    vector<int> ans = jobSequencingProblem(jobs);
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}