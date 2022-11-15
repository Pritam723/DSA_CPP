// https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268
#include<iostream>
#include <vector>
using namespace std;
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    //Write your code here
    vector<int> ans;
    for(int c = 0; c < mCols ; c++){
        if(c%2 == 0){ // Can also write !c&1
            for(int r = 0; r < nRows ; r++){
                ans.push_back(arr[r][c]);
            }
        }else{
            for(int r = nRows - 1; r >= 0 ; r--){
                ans.push_back(arr[r][c]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans = wavePrint(arr, arr.size(), arr[0].size());
    for(auto elem : ans){
        cout << elem << " ";
    }
}

