// https://www.codingninjas.com/codestudio/problems/find-unique_625159

#include<iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    //Write your code here
    /* 
    We can use hashmaps ofcourse. But see, here all the numbers have duplicate, except one.
    So, a cool trick is to do XOR. Surely, at last only the unique element remains.
    */
    int result = 0;
    for(int i = 0; i < size; i++){
        result = result ^ arr[i];
    }

    return result;

}

int main(){

    int len = 7;
    int arr[] = {2, 3, 1, 6, 3, 6, 2};

    int unique = findUnique(arr, len);

    cout << unique << endl;

    return 0;


}