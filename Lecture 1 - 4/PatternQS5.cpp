#include<iostream>
using namespace std;

// For N = 3
// *
// * * 
// * * *

// So, there is a relation B/W i and j here.

int main(){

    int N;
    cout << "Give your Input : ";
    cin >> N;
    int i = 1;
    while(i <= N){
        int j = 1;  // Change to j = i, while(j <= N) to see the mirrored Triangle.
        while(j <= i){
            cout << "* ";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;

    }

    return 0;
}