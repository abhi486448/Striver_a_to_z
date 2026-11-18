#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    printStack(st);
    cout<<temp<<" ";
}

void insertAtEnd(stack<int> &st,int el){
    if(st.empty()){
        st.push(el);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtEnd(st, el);
    st.push(temp);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int el = st.top();
    st.pop();

    reverseStack(st);

    insertAtEnd(st, el);
}

int main(){
    stack<int> st;
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(2);
    reverseStack(st);
    printStack(st);
    cout<<endl;
    return 0;
}