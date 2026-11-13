#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int nonOverlappingIntervals(vector<vector<int> > &intervals){
    sort(intervals.begin(), intervals.end(), compare);
    int nool = 0;
    int wt = INT_MIN;
    for(int i=0; i<intervals.size(); i++){
        if(wt<=intervals[i][0]){
            wt = intervals[i][1];
        }else {
            nool++;
        }
    }
    return nool;
}

int main(){
    vector<vector<int>> intervals = {{1, 2} , {2, 3} , {3, 4} ,{1, 3}};
    cout<<nonOverlappingIntervals(intervals)<<endl;
    return 0;
}