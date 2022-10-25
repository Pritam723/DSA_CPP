#include <bits/stdc++.h>
using namespace std;


////////////////// Both the solutions are wrong. ///////////////////////////////////////////////////////////////////////

// When round = 0, we can not let j go till j = n-1, because then j+1 will be index n, i.e. out of range. So, we are just
// getting lucky here that the garbage value at arr.end() is > arr[n-1]. But the correct sol. is j < round.


void bubbleSortSol1(vector<int>& arr, int n){   
    // Write your code here.
    for(int round = n-1; round >= 1; round--){  // Or do, for(round = 0; round < n-1 ; round++){}.
        //Here at round x we will fix index x. Intuitive.
        for(int j = 0; j <= round ; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void bubbleSortSol2(vector<int>& arr, int n){   
    // Write your code here.
    for(int round = 0; round < n-1 ; round++){
        //Here at round x we will fix index x. Intuitive.
        for(int j = 0; j < n-round ; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void printArray(vector<int> arr){

    for(auto elem : arr)
        cout << elem << " ";

}

void bubbleSort(vector<int> &arr, int n){
    for(int round = n-1; round >= 1; round--){
        // For round = n-1, we should check from j = 0 to index n-2. Coz we are doing j+1 swap anyway.
        // Simillarly, when round = 1, we check from j = 0 to 0 only, i.e. swap with index 0+1 only once if required.
        for(int j = 0; j <= round-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);

        }
    }
}

int main(){

    // vector<int> arr = {14,12,3,78,4,9,23,2};
    vector<int> arr = {6, 2, 8, 4, 10};

    // Solution bubbleSortSol1 and Sol2 are wrong. See reason.
    bubbleSort(arr, arr.size());

    printArray(arr);


}