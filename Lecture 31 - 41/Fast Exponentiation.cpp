#include<iostream>
using namespace std;

int fastExpo(int a, int b){

    // if(b == 1) return a; But this will not handle the case of b == 0
    if(b == 0) return 1; // This will handle both b = 1 and b = 0

    int sP = fastExpo(a, b >> 1);
    int bP;

    if(b & 1)
        bP = a * sP * sP;
    else
        bP = sP * sP;
    
    return bP;
    
}

int main(){
    int a = 2;
    int b = 10;
    cout << fastExpo(a,b);
}