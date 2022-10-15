// Leetcode 7
// https://leetcode.com/problems/reverse-integer/

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// #include<iostream>


// See one thing, In case of modulus operator, Sign always depends on numerator.
#include<iostream>
#include<math.h>
using namespace std;
// #include <bits/stdc++.h>


/* Integer Range is -2147483648 to 2147483647

Positive number case :
-----------------------
So, if I check like rev <= high/10, then we are basically checking,
rev <= 214748364, but suppose a number is like 9463847412, so rev is 2147483649 surely > INT_MAX,
but during previous iteration we will only check, 214748364 <= 214748364 which passes. But in this case,
I must check whether digit is <= 7 or not. So, if rev > 214748364, straightway reject it. If rev == 214748364 && digit > 7 then also reject it.

Negative number case :
-----------------------
-349 say. -349 % 10 will give -9,-4,-3
so rev = 10*rev + digit will give
-9 , -90 - 4 , -940 - 3. So, no need to change the main reversing logic. Check the constraint. See, we need to  check rev >= low/10, i.e. rev >= -214748364. But if,
the number is -9463847412, then the check in last iteration -214748364 >= -214748364 passes. So, I should see that the digit is not lesser than -8. So, check digit >= -8 or not.
So, if rev < -214748364, starightway reject it. If, rev == -214748364 && digit < -8, then also reject it.

*/

// Also, read this discussion to understand why the Code in link solution works.
// https://leetcode.com/problems/reverse-integer/discuss/1054279/faster-than-100.00-of-C%2B%2B-online-submissions


int main(){
    // cout << 14 % 3 << -14 % 3 << 14 % -3 << -14 % -3 <<endl;
    int low = -pow(2,31);
    int high = pow(2,31) - 1;
    int N;
    cin >> N;
    int rev = 0;
    while (N) {
        int digit = N % 10;
        N = N / 10;

        if(rev > high/10 || (rev == high/10 && digit > 7)) return 0;
        if(rev < low/10 || (rev == low/10 && digit < -8)) return 0;


        rev = 10 * rev + digit;
    }
    return rev;
    return 0;
}