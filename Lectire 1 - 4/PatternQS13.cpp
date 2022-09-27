#include<iostream>
using namespace std;

// For N = 4,
//       1
//     1 2 1  
//   1 2 3 2 1
// 1 2 3 4 3 2 1

// It has 3 parts. Space | Number increment | Number Decrement.
// 4 space, 3 space, 2 space, no space.


int main(){
    int N;
    cin >> N;
    int i = 1;
    while(i <= N){

        int spaces = N - i;
        int j = 1;
        while(spaces){
            cout<< " ";
            spaces--;
        }
        while(j <= i){
            cout << j;
            j++;
        }
        // Breaks when j = i + 1. Now I want to start from j = i - 1.
        j = j - 2;
        while(j > 0){
            cout << j;
            j--;
        }

        cout<<endl;
        i++;
    }

}