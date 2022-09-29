// Leetcode 191
// https://leetcode.com/problems/number-of-1-bits/

#include<iostream>
using namespace std;

int main(){

    int N;
    cin >> N;
    // So, one thing we can do is, we can divide by 2 and check whether it is an odd number. But the problem is that,
    // In case of negative numbers it will not work as 2's Complement system is being used. Ex. -3 is 11111...1011 (32 bits)

    // So, do right shift and then do AND operation with 00000...0001. If I get 1, then surely it has a set bit at LSB. Otherwise not.

    int mask = 1;
    int setBits = 0;
    for(int i = 0; i < sizeof(int) * 8 ; i++){
        setBits = setBits + (N & mask);
        N = N >> 1; 
    }
    cout << setBits;
    return 0;
}

// Follow up: If this function is called many times, how would you optimize it?
// See Notes, Leetcode.


