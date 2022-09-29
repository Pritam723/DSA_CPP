// Leetcode 1281
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

#include<iostream>
using namespace std;

int main(){

    int N;
    cin >> N;
    int sum = 0;
    int product = 1;

    while(N != 0){

        // cout << N%10 << endl;
        sum = sum + (N % 10);
        product = product * (N % 10);
        N = N/10;
    }
    // cout << product <<endl;
    // cout << sum;
    cout << (product-sum);


    return 0;
}