#include<bits/stdc++.h>
using namespace std;

double powF(double x, int n){
    long long N = n;
    double ans = 1;
    if(N<0){
        N=-N;
    }
    while(N){
        if(N%2){
            ans *= x;
            N--;
        }else {
            x = x*x;
            N = N/2;
        }
    }
    if(n<0){
        return (double)1.0/(double)ans;
    }
    return ans;
}
// complexcity
// time = O(n log n);
// space = O(1);

int main(){
    double x = 2.0000;
    int n = -2;
    cout<<powF(x, n)<<endl;
    return 0;
}