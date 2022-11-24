// https://www.codingninjas.com/codestudio/problems/binary-search_972

#include<iostream>
using namespace std;

int binarySearch(int arr[] , int s, int e, int key){
    if(s > e) return -1;
    int mid = s + (e - s)/2;
    if(arr[mid] == key) return mid;

    if(key > arr[mid])
        return binarySearch(arr, mid + 1, e, key);
    else
        return binarySearch(arr, s, mid - 1, key);

}

int main(){
    int n = 6;
    int key = 40;
    int arr[6] = {10,20,30,40,50,60};
    // cout << binarySearch(arr, 0, n, key); This is wrong,
    // Call with e = n - 1 actually.
    cout << binarySearch(arr, 0, n - 1, key);

}