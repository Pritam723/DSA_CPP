#include<iostream>
using namespace std;

int Binary_Search(int arr[], int N, int key){

    int low = 0;
    int high = N - 1;
    // int mid = (low + high)/2;
    int mid; // We are anyway calculating inside while(), so no need to give value here.

    while(low <= high){
        
        // mid = (low + high)/2;
        mid = low + (high - low)/2; // Same as above, but this will avoid low + high overflow error.


        if(key == arr[mid])
            return mid;
        else if(key > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
   }
    // We reach here implies that key is not found.
    return -1;    
}

int main(){

    int N = 7;
    int arr[N] = {10,20,30,40,50,60,70};

    cout << Binary_Search(arr, N, 60) << endl;


    return 0;
}