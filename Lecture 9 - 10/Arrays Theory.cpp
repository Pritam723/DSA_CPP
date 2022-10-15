#include<iostream>
#include<climits>
using namespace std;

// Find min, max in an array.

// Declaration
int getMin(int arr[], int len);
int getMax(int arr[], int len);


int main(){
    int len;
    cin >> len;

    int arr[100];

    for(int i = 0; i < len; i++){

        cin >> arr[i];

    }

    cout << "Minimum is " << getMin(arr, len) << endl;
    cout << "Maximum is " << getMax(arr, len) << endl;


}


int getMin(int arr[], int len){

    int mini = INT_MAX;
    // See, we are checking from 0 to len-1 index only. So, default filled 0s will not cause any issue.

    for(int i = 0; i < len; i++){

        mini = min(mini, arr[i]);
        
    }
    return mini;
}


int getMax(int arr[], int len){

    int maxi = INT_MIN;
    // See, we are checking from 0 to len-1 index only. So, default filled 0s will not cause any issue.

    for(int i = 0; i < len; i++){

        // maxi = max(maxi, arr[i]);

        if(arr[i] > maxi)
            maxi = arr[i]; 
        
    }
    return maxi;

}