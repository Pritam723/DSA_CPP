#include<iostream>
#include<vector>
using namespace std;

int findFirst(vector<int> &arr, int n, int k){
    int first = -1;
    int low = 0, high = n - 1;
    int mid = low + (high - low)/2;

    while(low <= high){
        if(k > arr[mid]){
            low = mid + 1;
        }else if(k < arr[mid]){
            high = mid - 1;
        }else{
            first = mid;
            high = mid - 1; // And continue searching. Since we continue searching in LHS, so updation of
            // fl.first will always lead to assigning it to a lesser index.
        }
        mid = low + (high - low)/2;
    }
    return first;
}

int findLast(vector<int> &arr, int n, int k){
    int last = -1;
    int low = 0, high = n - 1;
    int mid = low + (high - low)/2;

    while(low <= high){
        if(k > arr[mid]){
            low = mid + 1;
        }else if(k < arr[mid]){
            high = mid - 1;
        }else{
            last = mid;
            low = low + 1; // And continue searching. Since we continue searching in RHS, so updation of
            // fl.second will always lead to assigning it to a higher index.
        }
        mid = low + (high - low)/2;

    }
    return last;
}


pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k){
    pair<int, int> fl;

    fl.first = findFirst(arr, n, k);
    fl.second = findLast(arr, n, k);

    return fl;
  
}


int main(){

    // int N = 7;
    int key;
    cin >> key;
    vector<int> arr = {10,20,30,30,30,40,40,50,50,60,70};

    // cout << Binary_Search(arr, key) << endl;
    pair<int, int> fl = firstAndLastPosition(arr, arr.size(), key);

    cout << fl.first << " " << fl.second << endl;
    cout << "Thus no. of occurances is " << fl.second - fl.first ? fl.second - fl.first + 1 : 0;
    return 0;
}