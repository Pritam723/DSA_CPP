#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

}

void bubbleSort(int *arr, int n){

    if(n == 0 || n == 1) return;

    for(int i = 0; i < n-1 ; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    bubbleSort(arr, n-1);
}

int main(){
    int arr[] = {10,4,1,14,9};
    int n = 5;
    bubbleSort(arr, n);
    printArray(arr,n);
    
}