// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/


#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int>& arr) {
    int pivotIdx = 0;
    
    for(int i = 0; i < arr.size() - 1; i++){
        if(arr[i+1] < arr[i]){
            pivotIdx = i+1;
            break;
        }
    }
    
    if(pivotIdx == 0) return true;
    int j = pivotIdx;
    while(j < arr.size() - 1){
        if(arr[j+1] < arr[j]) return false;
        j++;
    }
    if(arr[j] > arr[0]) return false;
    return true;
    
}


bool checkSol2(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for(int i = 0; i < n-1 ; i++){
        if(arr[i+1] < arr[i])
            count++;
    }
    if(arr[0] < arr[n-1])
        count++;
    return (count <= 1);
    
}


int main(){
    int k;
    cin >> k;
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    cout << check(arr);
    // cout << n << " " << (n - (k%n))%n;
    
    return 0;
}


