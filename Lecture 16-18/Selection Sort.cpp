// https://www.codingninjas.com/codestudio/problems/selection-sort_981162

#include <bits/stdc++.h> 
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i = 0; i < n-1 ; i++){

        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }

}

void printArray(vector<int> arr){

    for(auto elem : arr)
        cout << elem << " ";

}

int main(){

    vector<int> arr = {10,12,45,22,13,9,0,43};
    selectionSort(arr,arr.size());
    printArray(arr);    

    return 0;

}