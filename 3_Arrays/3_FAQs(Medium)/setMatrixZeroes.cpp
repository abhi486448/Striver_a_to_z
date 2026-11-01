#include<bits/stdc++.h>
using namespace std;

// 34. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0. You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Explanation:
// Element at position (1,1) is 0, so set entire row 1 and column 1 to 0.
// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// Explanation:
// There are two zeroes: (0,0) and (0,3).
// Row 0 → all elements become 0
// Column 0 and column 3 → all elements become 0
// Constraints:
// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1

void setMatrixZero(vector<vector<int>> &matrix){
    map <int, pair<int, int>> mpp;
    int count=0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j]==0){
                mpp[count] = {i,j};
                count++;
            }
        }
    }
    for(auto m:mpp){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][m.second.second] = 0;
        }
        for(int j=0; j<matrix[m.second.first].size(); j++){
            matrix[m.second.first][j] = 0;
        }
    }
    
}
// complexcity 
// time O(n^3);
// space O(n^2);

// best
void bestSetMatrixZero(vector<vector<int>> &matrix){
    int col0 = 1;

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                if(j!=0){
                    matrix[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1; i<matrix.size(); i++){
        for(int j=1; j<matrix[i].size(); j++){
            if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    }
    if(matrix[0][0]==0){
        for(int i=0; i<matrix[0].size(); i++){
            matrix[0][i]=0;
        }
    }
    if(col0==0){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][0] = 0;
        }
    }
}
// complexcity 
// time O(n*m)
// space O(1);

int main(){
    vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
    // setMatrixZero(matrix);
    bestSetMatrixZero(matrix);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}