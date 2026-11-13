#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval){
    int n = intervals.size();
    vector<vector<int>> arr;
    int a = 0;
    while(a<n && intervals[a][1]<newInterval[0]){
        arr.push_back(intervals[a]);
        a++;
    }
    while(a<n && intervals[a][0]<=newInterval[1]){
        newInterval[0] = min(intervals[a][0], newInterval[0]);
        newInterval[1] = max(intervals[a][1], newInterval[1]);
        a++;
    }
    arr.push_back(newInterval);
    while(a<n){
        arr.push_back(intervals[a]);
        a++;
    }
    return arr;
}

int main(){
    vector<vector<int> > intervals={{1, 2},{3, 5},{6, 7},{8,10}};
    vector<int> newInterval={4,8};
    vector<vector<int> > ans=insertInterval(intervals, newInterval);
    for(auto i:ans){
        cout<<"[";
        for(auto a:i){
            cout<<" "<<a<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}