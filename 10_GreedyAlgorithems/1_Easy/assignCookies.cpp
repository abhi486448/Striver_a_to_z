#include<bits/stdc++.h>
using namespace std;

int assignCookies(vector<int> &stu,vector<int> &cookie){
    sort(stu.begin(), stu.end());
    sort(cookie.begin(), cookie.end());
    int count =0 ;
    int a = 0, b =0;
    while(a<stu.size() && b<cookie.size()){
        if(cookie[b]>=stu[a]){
            count++;
            b++;
            a++;
        } else {
            b++;
        }
    }
    return count;
}

int main(){
    vector<int> stu = {4, 5, 1};
    vector<int> cookie={6, 4, 2};
    cout<<assignCookies(stu, cookie)<<endl;
    return 0;
}