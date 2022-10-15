#include<iostream>
using namespace std;

void printArray(int arr[], int N){

    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }

    return;
}

int main(){
    int N = 6;
    int arr[N] = {0,1,1,0,0,1};
    int i = 0, j = N-1;

    while(i < j){
        if(arr[i] == 0)
            i++;
        else if(arr[j] == 1)
            j--;
        else{
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } 

    printArray(arr, N);

    return 0;
}