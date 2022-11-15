// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include<iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();

    int r = 0, c = nCols - 1;
    cout << "here1";
    while(r <= nRows-1 && c >= 0){  // r <= nRows is wrong. Since this is a vector, internal implementation will simply return upon error.
        cout << "here2";

        int element = matrix[r][c];

        if(target == element)
            return true;
        else if(target > element)
            r++;
        else
            c--;
    }
    cout << "here3";

    return false;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    cout << searchMatrix(arr,90);
}