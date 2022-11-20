// https://www.codingninjas.com/codestudio/problems/merge-sort_920442

#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

}

int partition(int *arr, int s, int e){
    
    int key = arr[e];

    int i = s;
    int j = s;

    while(i <= e-1){
        if(arr[i] > key){
            i++;
        }else{
            swap(arr[j],arr[i]);
            j++;
            i++;
        }
    }
    swap(arr[j],arr[e]);
    return j;
}


int partitionAlt(int *arr, int s, int e){
    // using first elemet as key.
    // {38,27,43,3,9,82,10} // {38,27,10,3,9,43,82}

    int key = arr[s];

    int i = e;
    int j = e;

    while(i >= s + 1){
        if(arr[i] < key){
            i--;
        }else{
            swap(arr[i],arr[j]);
            i--;
            j--;
        }
    }
    swap(arr[s],arr[j]);
    return j; 
}

void quickSort(int *arr, int s, int e){

    if(s > e) return; // s >= e is also fine becasue when s == e, it means we are dealing with an array of size 1.
    // Surely, array of size 1 is already has the pivot at correct place.

    int p = partitionAlt(arr,s,e);
    // Now Index p is fixed.
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}


int main(){
    int n = 7;
    int arr[7] = {38,27,43,3,9,82,10};
    //cout << partition(arr, 0, n-1) << endl; // Careful, don't send n here. Last index is n-1. MS() expects last index.

    quickSort(arr,0,n-1);
    printArray(arr, n); // Here I need to send length though.
}