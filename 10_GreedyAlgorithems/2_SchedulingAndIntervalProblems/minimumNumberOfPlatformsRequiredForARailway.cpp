#include<bits/stdc++.h>
using namespace std;

int minimumPlatform(vector<int> &at, vector<int> &dt){
    int n = at.size();
    if(n<1) return n;
    sort(at.begin(), at.end());
    sort(dt.begin(), dt.end());
    int cnt =0;
    int maxCnt = 0;
    int a=0; int b=0;
    while(a<n){
        if(at[a]<dt[b]){
            cnt++;
            a++;
        }else {
            cnt--;
            b++;
        }
        maxCnt = max(cnt, maxCnt);
    }
    return maxCnt;
}

int main(){
    vector<int> at={900, 940, 950, 1100, 1500, 1800};
    vector<int> dt={910, 1200, 1120, 1130, 1900, 2000};
    cout<<minimumPlatform(at, dt)<<endl;
    return 0;
}
