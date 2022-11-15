#include<iostream>
using namespace std;

int main(){
    
    int arr[11] = {10,20,30,40,50,60,70,80,90,100,101};

    int *ptr = arr;
    cout << *ptr << endl;
    cout << sizeof(&arr[0]) << endl;
    cout << sizeof(arr) << endl;

    
    return 0;
}