// https://www.codingninjas.com/codestudio/problems/reverse-the-array_1262298

#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr , int m){
	// Write your code here.
    int i = m + 1;
    int j = arr.size() - 1;

    while(i < j){
        swap(arr[i], arr[j]);    
        i++;
        j--;
    }
}

void printArray(vector<int> &arr){
    for(auto elem : arr){
        cout << elem << " ";
    }
}

int main(){
    int m;
    cin >> m;
    vector<int> arr = {1,2,3,4,5,6,7,8};
    reverseArray(arr,m);
    printArray(arr);
    return 0;
}