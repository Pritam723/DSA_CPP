#include<iostream>
using namespace std;

bool linearSearch(int arr[] , int n, int key){
    if(n == 0) return false;
    if(arr[0] == key) return true;

    bool sP = linearSearch(arr + 1, n - 1, key);
    bool bP = true && sP;
    return bP;

}

int main(){
    int n = 6;
    int key = 51;
    int arr[6] = {10,20,30,40,50,60};
    cout << linearSearch(arr, n, key);
}