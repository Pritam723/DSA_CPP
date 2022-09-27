#include<iostream>
using namespace std;

// For N = 4,
//    *
//   **
//  ***
// ****
int main(){
    int N;
    cin >> N;
    int i = 1;
    while(i <= N){
        int j = 1;
        while(j <= N){
            if(j <= N - i)
                cout<<" ";
            else
                cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }

}