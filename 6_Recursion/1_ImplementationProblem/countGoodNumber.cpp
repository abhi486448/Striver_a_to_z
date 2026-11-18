#include<bits/stdc++.h>
using namespace std;

long long pW(long long base, long long m){
    long long MOD = 1e9+7;
    base%=MOD;
    long long res=1;
    while(m>0){
        if(m%2){
            res = (res*base)%MOD;
        }
        base = (base*base)%MOD;
        m/=2;
    }
    return res;
}

long long countGood(long long n){
    long long MOD = 1e9+7;
    long long even =1;
    long long odd=1;
    if(n%2==0){
        even = pW(5, n/2);
        odd = pW(4, n/2);
    }else{
        even = pW(5, (n+1)/2);
        odd = pW(4, n/2);
    }
    return (even*odd)%MOD;
}

int main(){
    long long n=5;
    cout<<countGood(n)<<endl;
    return 0;
}