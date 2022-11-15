// https://leetcode.com/problems/rotate-image/description/
#include<iostream>
#include <vector>
using namespace std;

void transpose(vector<vector<int>>& matrix){
    int n = matrix.size(); // nRows = nCols = n here.
    for(int i = 0; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    int n = matrix.size();
    int s = 0, e = n-1;
    while(s < e){
        for(int r = 0; r < n; r++){
            swap(matrix[r][s],matrix[r][e]);
        }
        s++;
        e--;
    }
}


int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(arr);
    for(auto row : arr){
        for(int x : row){
            cout << x << " ";
        }
    }
}
