#include<iostream>
using namespace std;

int main(){

    int row, col;
    cout << "Enter no. of rows and cols : " << endl;
    cin >> row >> col;
    
    int **arr = new int* [row];
    for(int i = 0; i < row ; i++){
        arr[i] = new int[col];
    }

    // Taking Input

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cin >> arr[r][c];
        }
    }

    // Output

    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            cout << arr[r][c] << " ";
        }
        cout << endl;
    }

    // Releasing Heap Memory
    for(int r = 0; r < row; r++){
        delete []arr[r];
    }

    delete []arr;

    cout << endl << "Done." << endl;

    return 0;
}