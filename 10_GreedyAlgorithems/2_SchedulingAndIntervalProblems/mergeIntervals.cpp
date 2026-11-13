#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    vector<vector<int>> Merge;
    if(intervals.empty()) return Merge;
    sort(intervals.begin(), intervals.end(), compare);
    vector<int> temp = intervals[0];
    for(auto it:intervals){
        if(it[0]<=temp[1]){
            temp[1] = max(it[1], temp[1]);
        } else {
            Merge.push_back(temp);
            temp = it;
        }
    }
    Merge.push_back(temp);
    return Merge;
}

int main(){
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int> > ans = mergeIntervals(intervals);
    for(auto i:ans){
        cout<<"{";
        for(int it:i){
            cout<<" "<<it<<" ";
        }
        cout<<"}";
    }
    cout<<endl;
    return 0;
}