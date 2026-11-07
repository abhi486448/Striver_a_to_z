#include<bits/stdc++.h>
using namespace std;

struct Item{
    long long value;
    long long weight;
};

bool compare(Item a, Item b){
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;

    return r1>r2;
}

double fractionalKnapsack(vector<int> &val,vector<int> &wt,int capacity){
    int n = val.size();
    vector<Item> st(n);
    for(int i=0; i<n; i++){
        st[i] = {val[i], wt[i]};
    }
    sort(st.begin(), st.end(), compare);
    double sum = 0.0;
    for(int i=0; i<n; i++){
        if(st[i].weight<=capacity){
            sum+=st[i].value;
            capacity-=st[i].weight;
        } else {
            double rem = (double)st[i].value/st[i].weight;
            sum += (double)capacity*rem;
            break;
        }
    }
    return sum;
}

int main(){
    vector<int> val={60,100,120};
    vector<int> wt={10,20,30};
    int capacity = 50;
    cout<<fractionalKnapsack(val, wt, capacity)<<endl;
    return 0;
}