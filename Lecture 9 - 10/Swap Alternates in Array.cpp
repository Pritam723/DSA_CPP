#include<iostream>
using namespace std;

void swapAlternate(int arr[], int len){

    /* Check the logic with len = even and len = odd.
    
    Say arr[] = {1,2,3,4,5,6}, len is 6. So at last iteration i = 4, j = 5
    They will be swapped. i = 5, j = 7. So, no need to loop again.

    Say arr[] = {1,2,3,4,5,6,7}, len = 7. So, i = 4, j = 5.
    They will be swapped. i = 5, j = 7 which is not < len. So, no need to loop again.


    So, in the condition we can just check j < len, no need to check i < len at all.

    */

    // Also think about it, no need to check if len < 2 or not. While Condition takes care of that case.

    int i = 0, j = 1;

    // if(len < 2)
    //     return;

    while(j < len){
        swap(arr[i], arr[j]);
        i = i + 2;
        j = j + 2;
    }


}

void swapAlternateSol2(int arr[], int len){
    // Since, j is always i + 1, so we can simply use one variable.
    // Also think about it, no need to check if len < 2 or not. While Condition takes care of that case.
    int i = 0;

    // if(len < 2)
    //     return;

    while(i + 1 < len){
        
        swap(arr[i], arr[i + 1]);
        
        i = i + 2;
        
    }


}



int main(){
    int len;
    cin >> len;
    int arr[100];

    for(int i = 0 ; i < len ; i++){
        cin >> arr[i];
    }

    swapAlternateSol2(arr, len);

    cout << "Printing the reversed array : " << endl;

    for(int i=0 ; i < len ; i++){
        cout << arr[i] << " ";
    }


    return 0;
}