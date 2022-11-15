// https://leetcode.com/problems/spiral-matrix/

#include<iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int total = rows*cols;

    int firstRow = 0;
    int lastRow = rows - 1;
    int firstCol = 0;
    int lastCol = cols - 1;
    int count = 1;
    while(count <= total){
        // First Row
        for(int c = firstCol; count <= total && c <= lastCol ; c++){
            ans.push_back(matrix[firstRow][c]);
            count++;
        }
        firstRow++;
        // Last Column
        for(int r = firstRow; count <= total && r <= lastRow ; r++){
            ans.push_back(matrix[r][lastCol]);
            count++;
        }
        lastCol--;
        // Last Row
        for(int c = lastCol; count <= total && c >= firstCol ; c--){
            ans.push_back(matrix[lastRow][c]);
            count++;
        }
        lastRow--;
        // First Column
        for(int r = lastRow; count <= total && r >= firstRow ; r--){
            ans.push_back(matrix[r][firstCol]);
            count++;
        }
        firstCol++;
    }
return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(arr);
    for(auto x : ans){
        cout << x << " ";
    }
}










// vector<int> printSideElements(vector<vector<int>> arr, int fromRow, int toRow, int fromCol, int toCol){
//     vector<int> ans;
//     cout << fromRow << " " << toRow << " " << fromCol << " " << toCol << endl;
//     for(int  c = fromCol; c <= toCol ; c++){
//         cout << arr[fromRow][c];
//         ans.push_back(arr[fromRow][c]);
//     }
//     cout << endl;

//     for(int  r = fromRow + 1; r <= toRow ; r++){
//         cout << arr[r][toCol];
//         ans.push_back(arr[r][toCol]);
//     }    
//     cout << endl;

//     for(int  c = toCol - 1; c >= fromCol ; c--){
//         cout << arr[toRow][c];
//         ans.push_back(arr[toRow][c]);
//     }    
//     cout << endl;

//     for(int  r = toRow - 1; r >= fromRow + 1 ; r--){
//         cout << arr[r][fromCol];
//         ans.push_back(arr[r][fromCol]);

//     }    
//     cout << endl;
//     return ans;

// }

// vector<int> spiralOrder(vector<vector<int>>& matrix) {
//     int nRows = matrix.size();
//     int nCols = matrix[0].size();
//     vector<int> ans;
//     int fromRow = 0, toRow = nRows - 1, fromCol = 0, toCol = nCols - 1;
//     for(int count = 1; count <= (nRows+1)/2 ; count++){
//         vector<int> partialAns = printSideElements(matrix, fromRow, toRow, fromCol, toCol);
//         for(int elem : partialAns){
//             ans.push_back(elem);
//         }
//         fromRow++;
//         toRow--;
//         fromCol++;
//         toCol--;
//     }
//     return ans;
// }