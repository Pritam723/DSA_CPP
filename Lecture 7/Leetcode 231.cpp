// Leetcode 231. Power of Two
// https://leetcode.com/problems/power-of-two/

#include<iostream>
using namespace std;

// If, N <= 0 return False.
// One thing we can do is, count no. of set bits. It must be 1.
// Another approach : WKT, n & (n-1) drops the least set bit. So, my number must become 0, if it has only one set bit.

bool isPowerOfTwo(int N){

    if(N <= 0)
        return false;
    int setBits = 0;
    while(N){
        setBits = setBits + (N & 1);
        N = N >> 1;
    }
    return setBits == 1 ? true : false; 

}

bool isPowerOfTwoSol2(int N){

    if(N <= 0)
        return false;

    N = N & (N-1);
    return !N ? true : false; 

}

int main(){

    int N;
    cin >> N;

    cout << isPowerOfTwoSol2(N);

    return 0;
}