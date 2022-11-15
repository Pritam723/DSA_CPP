// https://leetcode.com/problems/move-zeroes/

#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
	// Write your code here.

}

void printArray(vector<int> &arr){
    for(auto elem : arr){
        cout << elem << " ";
    }
}

int main(){
    int m;
    cin >> m;
    vector<int> arr = {0,1,0,3,12};
    moveZeroes(arr);
    printArray(arr);
    return 0;
}