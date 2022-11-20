// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/

#include<iostream>
using namespace std;

int mergeInv(int *arr, int s,int m, int e){

    int invM = 0;
    int l = m-s+1, r = e-m;
    int *L = new int[l];
    int *R = new int[r];
    
    // Filling up the arrays.
    for(int t = s; t <= m; t++){
        L[t-s] = arr[t];
    }
    for(int t = m+1; t <= e; t++){
        R[t-(m+1)] = arr[t];
    }


    int i = 0, j = 0, k = s;

    while(i < l && j < r){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
            invM = invM + (l - i); // See explanation in notes why.
        }
    }

    while(i < l){
        arr[k++] = L[i++];
    }
    while(j < r){
        arr[k++] = R[j++];
    }

    delete []L;
    delete []R;

    
    return invM;

}


int countInv(int *arr, int s, int e){
    if(s >= e) return 0;

    int m = s + (e-s)/2;

    int invL = countInv(arr,s,m);
    int invR = countInv(arr,m+1,e);

    int invM = mergeInv(arr,s,m,e);


    return invL + invR + invM;

}


int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
 
    return inv_count;
}


int main(){
    int n = 2;
    int arr[2] = {3, 3};

    // int arr[] =     {3,5,6,9,1,2,7,8};


    cout << countInv(arr, 0, n-1); // Careful, don't send n here. Last index is n-1. MS() expects last index.
    // cout << getInvCount(arr, n);
}