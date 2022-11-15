// https://leetcode.com/problems/search-a-2d-matrix/

#include<iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int s = 0, e = m*n - 1;
    int mid = s+(e-s)/2;
    int r = mid/n;
    int c = mid%n;
    while(s <= e){
        if(matrix[r][c] == target){
            return true;
        }else if(target > matrix[r][c]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        mid = s+(e-s)/2;
        r = mid/n;
        c = mid%n;
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    cout << searchMatrix(arr,15);
}