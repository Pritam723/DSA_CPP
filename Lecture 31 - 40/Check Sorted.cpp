#include<iostream>
using namespace std;

bool checkSorted(int arr[], int n){
    if(n == 1) return true;
    if(arr[0] > arr[1]) return false;

    return checkSorted(arr + 1, n - 1);
}

int main(){
    int n = 6;
    int arr[6] = {10,20,30,23,50,60};
    cout << checkSorted(arr, n);
}