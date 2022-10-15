// DNF Algorithm
// https://www.codingninjas.com/codestudio/problems/sort-0-1-2_631055

#include<iostream>
using namespace std;

void printArray(int arr[], int N){

    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }

    return;
}

void sort012(int *arr, int n)
{
   //   Write your code here
   int low = 0, mid = 0, high = n-1;
   while(mid <= high){

        switch(arr[mid]){

            case 0 :
                swap(arr[mid], arr[low]);
                low++;
                mid++;
                break;
            case 1 :
                mid++;
                break;
            case 2 :
                swap(arr[mid], arr[high]);
                high--;
                break;
        } 
}
    
}

int main(){
    int N = 9;
    int arr[N] = {0,2,2,1,0,1,1,0,2};
    
    sort012(arr, N);

    printArray(arr, N);

    return 0;
}