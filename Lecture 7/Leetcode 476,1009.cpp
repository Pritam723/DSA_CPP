// Leetcode 476,1009
// https://leetcode.com/problems/complement-of-base-10-integer/
// https://leetcode.com/problems/number-complement/
// Edge Case, N = 0;
#include<iostream>
#include<math.h>
using namespace std;

int solution1(int N){


    if(N == 0)
    // This case is exception. Don't return INT_MIN here, as we are only taking no. of bits which are required.
    return 0;
    
    int complementNumber = 0;
    int loopCounter = 0;

    while(N){

        int digit = !(N & 1);
        complementNumber = pow(2,loopCounter) * digit + complementNumber;
        N = N >> 1;
        loopCounter++;
    }
    return complementNumber;
}

int solution2(int N){

    if(N == 0)
        return 1;

    int originalNumber = N;
    // See, 5 = 101, ~5 = 11111...010. But I only want 010 part. So, try to make a mask like 0000...0111, and finally AND with ~5 to get desired ans i.e. 2.

    int mask = 0;
    while(N){

        // Left Shift and OR with 1 will make our mask.
        mask = mask << 1;
        mask = mask | 1;

        N = N >> 1;
    }

    // Finally, return ~5 & mask.
    return ~originalNumber & mask;
    // But this also does not cover the N == 0 case.


}



int main(){

    int N;
    cin >> N;

    int ans = solution2(N);

    cout << ans;


    return 0;
}