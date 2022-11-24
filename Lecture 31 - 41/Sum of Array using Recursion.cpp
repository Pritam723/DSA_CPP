#include<iostream>
using namespace std;

int getSum(int *arr, int n){
    
    // We can write the base condition as 
    // if(n == 0) return 0 too. Our bp = arr[0] + sp; will handle it.
    if(n == 1) return arr[0];
    
    int smallerProblem = getSum(arr + 1, n - 1);
    int biggerProblem = arr[0] + smallerProblem;
    return biggerProblem;


}

int main(){
    int n = 6;
    int arr[6] = {10,20,30,40,50,60};
    cout << getSum(arr, n);
}