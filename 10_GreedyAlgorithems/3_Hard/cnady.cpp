#include<bits/stdc++.h>
using namespace std;

int candy(vector<int> &ratings){
    int sum=1, i=1;
    int n = ratings.size();
    while(i<n){
        while(i<n && ratings[i]==ratings[i-1]){
            sum+=1;
            i++;
        }
        int peak =1;
        while(i<n && ratings[i]>ratings[i-1]){
            peak+=1;
            sum+=peak;
            i++;
        }
        int down =1;
        while(i<n && ratings[i]<ratings[i-1]){
            sum+=down;
            down++;
            i++;
        }

        if(down>peak){
            sum = sum+down-peak;
        }
    }
    return sum;
}

int main(){
    vector<int> ratings={1, 2, 1, 4, 5};
    cout<<candy(ratings)<<endl;
    return 0;
}