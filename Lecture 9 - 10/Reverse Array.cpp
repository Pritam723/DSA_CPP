#include<iostream>
using namespace std;

void reverseArray(int arr[], int len){

    for(int i = 0, j = len - 1 ; i < j ; i++, j--){

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

    }
    // No need to return anything, we are changing at address level.
}

int main(){
    int len;
    cin >> len;
    int arr[100];

    for(int i = 0 ; i < len ; i++){
        cin >> arr[i];
    }

    reverseArray(arr, len);

    cout << "Printing the reversed array : " << endl;

    for(int i=0 ; i < len ; i++){
        cout << arr[i] << " ";
    }


    return 0;
}