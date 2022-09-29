#include <iostream>
using namespace std;

int main() {

    int N;
    cout << "Give Input : " << endl;
    cin >> N;

    int row = 1;
    int col;
    while(row <= N) {
        // cout << row;
        col = 1;
        while(col <= N){

            cout << N - col + 1 << " ";
            col++;
        }
        cout << endl;
        row = row + 1;
    }

    return 0;
}