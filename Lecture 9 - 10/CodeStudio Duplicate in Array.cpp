// https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397
// Duplicate in Array.

/* 
You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. 
There is a single integer value that is present in the array twice. Your task is to find the duplicate integer 
value present in the array.
Duplicate value is always present in the array.

Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
*/


// See, if I First XOR 1 to N-1, then I will get mux = XOR(1 to N-1) say. Now muxArr = XOR(all array elements) say. Surely, if 
// the element 4 is repeated, then 4 XOR 4 = 0. So, actually, in muxArr we don't have 4's data. However in mux we have 4's data.
// So, finally if we XOR(mux, muxArr), then we will get 4.
#include<iostream>
using namespace std;

int findDuplicate(int arr[], int len) 
{
    // Write your code here
    int mux = 0, muxArr = arr[0];
    for(int i = 1; i <= len - 1; i++){
        mux = mux ^ i;
        muxArr = muxArr ^ arr[i];
    }

	return mux ^ muxArr;
}


int main(){

    int len = 5;
    int arr[] = {1, 2, 3, 4, 4};

    int duplicate = findDuplicate(arr, len);

    cout << duplicate;




}