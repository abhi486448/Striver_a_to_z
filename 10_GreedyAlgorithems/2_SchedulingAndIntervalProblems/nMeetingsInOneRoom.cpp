#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int nMeetingInOneRoom(vector<int> &start,vector<int> &end){
    vector<vector<int> > meeting(start.size());
    for(int i=0; i<meeting.size(); i++){
        meeting[i] = {start[i], end[i]};
    }
    sort(meeting.begin(), meeting.end(), compare);

    int wt = 0;
    int nom = 0;

    for(int i=0; i<meeting.size(); i++){
        if(wt<meeting[i][0]){
            nom++;
            wt = meeting[i][1];
        }
    }
    return nom;
}

int main(){
    vector<int> start={1, 3, 0, 5, 8, 5};
    vector<int> end={2, 4, 6, 7, 9, 9};
    cout<<nMeetingInOneRoom(start, end)<<endl;
    return 0;
}