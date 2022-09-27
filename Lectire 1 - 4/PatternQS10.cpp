#include<iostream>
using namespace std;

// For N = 4,
// A
// B C
// C D E
// D E F G



int main(){

    int N;
    cin >> N;
    int i = 1;
    while(i <= N){
        char start = 'A' + i - 1;
        int j = 1;
        while(j <= i){

            cout << char(start + j - 1) << " ";
            j++;
        }
        cout << endl;
        i++;
    }


}