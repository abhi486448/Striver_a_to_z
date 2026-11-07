#include<bits/stdc++.h>
using namespace std;

bool lemonadeChnage(vector<int> &bills){
    int a5 = 0;
    int b10 = 0;
    for(int i=0; i<bills.size(); i++){
        if(bills[i]==5){
            a5++;
        } else if(bills[i]==10){
            if(a5>0){
                a5--;
                b10++;
            }else {
                return 0;
            }
        }else {
            if(a5>0 && b10>0){
                b10--;
                a5--;
            }else if(a5>=3){
                a5-=3;
            }else {
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> bills={5, 5, 10, 5, 20};
    cout<<lemonadeChnage(bills)<<endl;
    return 0;
}