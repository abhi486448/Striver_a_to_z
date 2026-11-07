#include<bits/stdc++.h>
using namespace std;

long long shortingJobFirst(vector<int> &pr){
    sort(pr.begin(), pr.end());
    long long wt = 0;
    long long avg = 0;
    for(int i=0; i<pr.size(); i++){
        avg+=wt;
        wt+=pr[i];
    }
    avg/=pr.size();
    return avg;
}

int main(){
    vector<int> pr={4, 1, 3, 7, 2};
    cout<<shortingJobFirst(pr)<<endl;
    return 0;
}