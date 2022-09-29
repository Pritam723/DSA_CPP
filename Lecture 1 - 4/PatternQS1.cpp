#include<iostream>
using namespace std;

int main(){

    cout << "Enter your number : ";
    int N;
    cin >> N;

    int row = 1;
    
    while (row <= N){
        int col = 1;
        while(col <= N){

            cout << row;
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }
    

    return 0;
}