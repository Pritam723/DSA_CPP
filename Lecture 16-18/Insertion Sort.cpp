#include <bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    // Write your code here.
    for(int i = 1; i < n ; i++){
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0; j--){
            if(arr[j] < key)
                break;
            else
                arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void printArray(vector<int> arr){

    for(auto elem : arr)
        cout << elem << " ";

}

int main(){
    vector<int> arr = {12,9,80,3,4,70,22};
    insertionSort(arr.size(),arr);
    printArray(arr);

    return 0;
}