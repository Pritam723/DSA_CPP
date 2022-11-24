#include<iostream>
using namespace std;

int power(int n){
    // Base Condition. 2^0 = 1.
    if(n == 0)
        return 1;
    
    // Smaller Problem
    int sp = power(n-1);

    // Bigger problrm
    int bp = 2 * sp;

    return bp;
}

int main(){
    int n;
    cin >> n;

    cout << power(n);
}