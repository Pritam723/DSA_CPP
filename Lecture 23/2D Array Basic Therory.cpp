#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> rowWiseSum(int arr[][4], int row, int col){
    vector<int> ans;
    for(int i = 0; i < row ; i++){
        int rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum = rowSum + arr[i][j];
        }
        ans.push_back(rowSum);
    }
    return ans;
}


pair<int,int> largestRowSum(int arr[][4], int row, int col){
    pair <int, int> ans = make_pair(-1,INT_MIN);
    for(int i = 0; i < row ; i++){
        int rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum = rowSum + arr[i][j];
        }

        if(rowSum > ans.second){
            ans.second = rowSum;
            ans.first = i;
        }
    }
    return ans;
}

void print2DArray(int arr[3][4], int row, int col){
    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int row, col;
    // cout << "Input no. of rows and columns : ";
    // cin >> row;
    // cin >> col;
    row = 3;
    col = 4;
    int arr[3][4];
    // arr is BA of an 1D array. arr is pointer to 1D array.

    for(int i = 0; i < row ; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    print2DArray(arr, row, col);

    vector<int> rowSumVec = rowWiseSum(arr, row, col);
    for(int elem : rowSumVec){
        cout << elem;
    }

    cout << "Largest row index is : " << largestRowSum(arr, row, col).first << ". And the Sum is : " << largestRowSum(arr, row, col).second;

}