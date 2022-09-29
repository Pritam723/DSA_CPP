#include<iostream>
using namespace std;

// For N = 3,
// A B C
// B C D
// C D E

int main(){

    int N;
    cin >> N;

    int i = 1;
    
    while(i <= N){
        int j = 1;
        char start = 'A' + i - 1;
        while(j <= N){
            char characterToPrint = start + j - 1;
            cout << characterToPrint;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}