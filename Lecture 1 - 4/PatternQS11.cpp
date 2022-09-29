#include<iostream>
using namespace std;

// For N = 4,
// D
// C D
// B C D E
// A B C D



int main(){

    int N;
    cin >> N;
    int i = 1;
    while(i <= N){
        int j = 1;
        //char start = ('A' + N - 1) - i + 1; // = 'A' + N - i
        while(j <= i){

            //cout << char(start + j - 1);
            cout << char('A' + N - i + j - 1);

            j++;
        }
        cout<< endl;
        i++;
    }


}