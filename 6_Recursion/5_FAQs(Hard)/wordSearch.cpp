#include<bits/stdc++.h>
using namespace std;

bool checkS(int t,int i,int j,string &word,vector<vector<char>> &board){
    if(t==word.size()) return true;

    if(j-1>=0){
        if(board[i][j-1]==word[t]){
            board[i][j-1]='#';
            if(checkS(t+1, i, j-1, word, board)) return true;
            board[i][j-1]=word[t];
        }
    }
    if(j+1<board[i].size()){
        if(board[i][j+1]==word[t]){
            board[i][j+1]='#';
            if(checkS(t+1, i, j+1, word, board)) return true;
            board[i][j+1]=word[t];
        }
    }
    if(i-1>=0){
        if(board[i-1][j]==word[t]){
            board[i-1][j]='#';
            if(checkS(t+1, i-1, j, word, board)) return true;
            board[i-1][j]=word[t];
        }
    }
    if(i+1<board.size()){
        if(board[i+1][j]==word[t]){
            board[i+1][j]='#';
            if(checkS(t+1, i+1, j, word, board)) return true;
            board[i+1][j]=word[t];
        }
    }
    return false;
}

bool serchString(vector<vector<char>> &board,string &word){
    if(word.empty()) return true;

    int t=0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j]==word[t]){
                board[i][j]='#';
                if(checkS(t+1, i, j, word, board)) return true;
                board[i][j]=word[t];
            }
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board={{'A', 'B', 'C', 'E'},{'S' ,'F' ,'C' ,'S'},{'A', 'D', 'E', 'E'}};
    string word="ABCCED";
    bool check = serchString(board, word);
    if(check){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}