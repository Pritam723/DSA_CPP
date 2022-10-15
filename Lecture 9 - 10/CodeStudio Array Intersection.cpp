// https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149

/*
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively.
Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.
Can we solve this problem using the time complexity of O(max(N, M)).
Example :

i/p -->  [1 2 2 2 3 4] and [2 2 3 3]
o/p --> 3 2

*/


#include<iostream>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;


vector<int> findArrayIntersectionUniqueOnly(vector<int> &arr1, int n, vector<int> &arr2, int m){
	// Write your code here.
    int i = 0, j = 0;
    int lastMatched = - 1; // In constraints it is given that array elements are >= 0. So, it's fine.
    vector<int> arrayIntersection;
    while(i < n  && j < m){
        if(arr1[i] == arr2[j]){
            if(arr1[i] != lastMatched){ // We are here, it means both arr[i] = arr[j] = lastmatched.
                arrayIntersection.push_back(arr1[i]);
                lastMatched = arr1[i];
            }
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    // Now when one of the conditions hit, we are sure that either i = n or j = m now. So, for rest of the elements
    // Do I need to run while loop? Like we do during Merge() ? Actually NO. Cause we are simply doing Intersection.

    return arrayIntersection;

}


vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
    // Write your code here.
    int i = 0, j = 0;

    vector<int> arrayIntersection;

    while(i < n  && j < m){
        if(arr1[i] == arr2[j]){
            arrayIntersection.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }

    // Now when one of the conditions hit, we are sure that either i = n or j = m now. So, for rest of the elements
    // Do I need to run while loop? Like we do during Merge() ? Actually NO. Cause we are simply doing Intersection.

    return arrayIntersection;

}



int main(){

    vector<int> arr1 = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 3};

    vector<int> arrayIntersection = findArrayIntersection(arr1, 6, arr2, 4);

    for(int item : arrayIntersection){
        cout << item << " ";
    }

    return 0;
}