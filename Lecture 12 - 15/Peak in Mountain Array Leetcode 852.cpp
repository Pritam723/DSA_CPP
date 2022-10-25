// Leetcode 852. Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    // int low = 0, high = arr.size() - 1;
    int low = 1, high = arr.size() - 2;

    int mid = low + (high - low)/2;
    while(low <= high){  // Can give while(1) too, coz we are sure it will halt.
        if(arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]){
            low = mid + 1;
        }
        else if(arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]){
            high = mid - 1;

        }
        else{
            break;
        }
    mid = low + (high - low)/2;
    }

    return mid;
}

int peakIndexInMountainArraySol2(vector<int>& arr) {
    // int low = 0, high = arr.size() - 1;
    int low = 0, high = arr.size() - 1;

    int mid = low + (high - low)/2;

    while(low < high){
        if(arr[mid] < arr[mid+1])
            low = mid + 1;
        else
            high = mid;

        mid = low + (high - low)/2;

    }



    return low; // Can return high, mid also.
}

int main(){

    vector<int> arr = {3,5,3,2,0};

    cout << "Index is : " << peakIndexInMountainArraySol2(arr);

    return 0;
}

