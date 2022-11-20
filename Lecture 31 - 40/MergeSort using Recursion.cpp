// https://www.codingninjas.com/codestudio/problems/merge-sort_920442

#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

}

void merge(int *arr, int s, int m, int e){
    int *L = new int [m-s+1];
    int *R = new int[e-m];

    for(int i = s; i <= m; i++){
        L[i-s] = arr[i];
    }
    
    for(int i = m+1; i <= e; i++){
        R[i-m-1] = arr[i];
    }
    // Now my 2 arrays are ready. Use the arr[] array space only to fill it up.

    int i = 0,j = 0, k = s; // Can do i = s, j = m+1 too. But the we have to change indexing.

    while(i < m-s+1 && j < e-m){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Now, one array may still remain.

    while(i < m-s+1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < e-m){
        arr[k] = R[j];
        j++;
        k++;
    }

    delete []L;
    delete []R;

}

void mergeSort(int *arr, int s, int e){
    if(s >= e) return;
    int m = s + (e-s)/2;

    mergeSort(arr,s,m);
    mergeSort(arr,m+1,e);

    merge(arr,s,m,e);

}

int main(){
    int n = 7;
    int arr[7] = {38,27,43,3,9,82,10};
    mergeSort(arr, 0, n-1); // Careful, don't send n here. Last index is n-1. MS() expects last index.
    printArray(arr, n); // Here I need to send length though.
}