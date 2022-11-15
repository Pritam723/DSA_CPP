// https://leetcode.com/problems/rotate-array/


#include<iostream>
#include<vector>
using namespace std;

void rotateArray(vector<int> &arr , int k){
	// Write your code here.
    vector<int> ans;
    int n = arr.size();
    int i = (n - (k % n))%n;

    do{
        ans.push_back(arr[i]);
        i = (i+1)%n;

    }while(i != (n - (k % n))%n);

    arr = ans;


}

void reversePartial(vector<int> &arr, int start, int end){
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}


void rotate(vector<int> &arr , int k){
    // Write your code here.
        // Write your code here.
        int n = arr.size();
        int pivot = k%n;
        int i = 0;
        
        // Reverse whole array.
        reversePartial(arr,0,n-1);
        // Reverse from 0 to pivot-1.
        reversePartial(arr,0,pivot-1);
        // Reverse from pivot to n-1
        reversePartial(arr,pivot,n-1);
}


void printArray(vector<int> &arr){
    for(auto elem : arr){
        cout << elem << " ";
    }
}

int main(){
    int k;
    cin >> k;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
    int n = arr.size();
    rotate(arr,k);
    printArray(arr);
    // cout << n << " " << (n - (k%n))%n;
    
    return 0;
}


