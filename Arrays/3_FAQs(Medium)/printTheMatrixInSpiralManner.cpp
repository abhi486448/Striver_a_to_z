#include<bits/stdc++.h>
using namespace std;

// 107. Print the matrix in spiral manner
// Given an M * N matrix, print the elements in a clockwise spiral manner.

// Return an array with the elements in the order of their appearance when printed in a spiral manner.
// Example 1:
// Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]
// Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
// Explanation:
// The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5
// Example 2:
// Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]
// Output: [1, 2, 3, 4, 8, 7, 6, 5]
// Explanation:
// The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -100 <= matrix[i][j] <= 100

vector<int> printTheMatrix(vector<vector<int>> &nums){
    int n = nums[0].size();
    int m = nums.size();
    int top = 0;
    int bottum = m-1;
    int left = 0;
    int right = n-1;
    vector<int> result;

    while(top <= bottum && left <= right){
        for(int i=left; i<=right; i++){
        result.push_back(nums[top][i]);
        }
        top++;
        for(int i=top; i<=bottum; i++){
            result.push_back(nums[i][right]);
        }
        right--;
        if(top<=bottum){
            for(int i=right; i>=left; i--){
                result.push_back(nums[bottum][i]);
            }
            bottum--;
        }
        if(left<=right){
            for(int i=bottum; i>top; i--){
                result.push_back(nums[i][left]);
            }
            left++;
        }
    }
    // if(top<=bottum && left<=right){
    //     result.push_back(nums[top][left]);
    // }


    return result;
}

int main(){
    vector<vector<int>> nums{{1}, {4}, {7}};
    vector<int> result = printTheMatrix(nums);

    for(auto a:result){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
// note:-
// - check contidions cairfuly otherwise you will end up segementation error
// - inside loop we checked if top<=bottum and left<=right so for first(left to right) and first(top to bottum) there is no need for any checks
// but after that there is need to check top<=bottum for(right to left) and left<=right for(bottum to top)