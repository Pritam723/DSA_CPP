#include<iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 . . .

int main(){

    int N; /* N should be > 0 */
    cout << "Give Input : ";
    cin >> N;

    int first = 0;
    int second = 1;
    int temp;
    if(N < 1){
        cout << "No numbers to output";
    }
    else if(N == 1){
        cout << first << " ";
    }else{
        cout << first << " " << second << " ";
        while(N > 2){
            temp = second;
            second = first + second;
            first = temp;
            cout << second << " ";
            N--;
        }
    }
    return 0;
}