#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string s){
    int cmin = 0;
    int cmax = 0;

    for(auto c:s){
        if(c=='('){
            cmin++;
            cmax++;
        } else if(c==')'){
            cmin = max(0, cmin-1);
            cmax--;
        } else {
            cmin = max(0, cmin-1);
            cmax++;
        }

        if(cmax<0) return false;
    }

    return cmin==0;
}

int main(){
    string s="*(()";
    bool ans = validParenthesis(s);
    if(ans) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}