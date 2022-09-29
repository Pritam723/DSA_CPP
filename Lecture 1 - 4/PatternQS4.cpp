#include<iostream>
using namespace std;

// For N = 3
// 1 2 3
// 4 5 6
// 7 8 9

// So it is basically line break after N numbers. Always i++

int main(){

    int N;
    cout << "Give your Input : ";
    cin >> N;

    int i = 1;
    while(i <= N*N){
        cout << i << " ";
        if(i % N == 0)
            cout << endl;
        i++;

    }


    return 0;
}