// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

/*
N = Length of array.
K = No. of total Cows.
stalls = The array given.

Ex. 

K = 4
{0 3 4 7 10 9} o/p is 3.

K = 3
{0 4 3 7 10 9} o/p is 4.

See detailed explanation in notes.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPlacementPossible(vector<int> &stalls, int size, int k, int d){
    int cowCount = 1;
    int lastCowPosition = 0;

    for(int i = 1; i < size; i++){
        if(stalls[i] - stalls[lastCowPosition] >= d){
            lastCowPosition = i;
            cowCount = cowCount + 1;
        }

        if(cowCount == k) return true;
    }

    return false;

}


int aggressiveCows(vector<int> &stalls, int k){
    int ans;
    // sort(stalls.begin(), stalls.end());

    int size = stalls.size();
    int s = 0, e = stalls[size - 1] - stalls[0];
    int d = s + (e-s)/2;

    while(s <= e){
        if(isPlacementPossible(stalls,size,k,d)){
            ans = d;
            s = d + 1;
        }else{
            e = d - 1;
        }

        d = s + (e-s)/2;
    }

    return ans;
}



int main(){

    vector<int> stalls = {4, 2, 1, 3, 6};
    int k = 2;
    sort(stalls.begin(), stalls.end());
    // While submitting, sort the array in aggressiveCows() function. And that will be a better practice too.
    cout << "Maximum distance we can place the cows in is " << aggressiveCows(stalls, k) << endl;


    return 0;
}