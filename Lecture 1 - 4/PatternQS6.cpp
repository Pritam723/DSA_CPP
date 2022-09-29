#include<iostream>
using namespace std;

// For N = 4;
// Print : 
// 1
// 2 3
// 4 5 6
// 7 8 9 10

int main(){
    int N;
    cin >> N;

    int i = 1;
    int count = 1;
    while(i <= N){
        int j = 1;
        while(j <= i){
            cout << count << " ";
            count++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}