#include<iostream>
using namespace std;

// For N = 4,
// 1
// 2 3
// 3 4 5
// 4 5 6 7

// Always start with Row No.

int main(){
    int N;
    cout << "Your input : " << endl;
    cin >> N;

    int i = 1;
    while (i <= N){
        
        int j = 1;
        while(j <= i){
            cout << i+j-1 << " ";
            j++;
        }

        cout << endl;
        i++;

    }
    

    return 0;
}