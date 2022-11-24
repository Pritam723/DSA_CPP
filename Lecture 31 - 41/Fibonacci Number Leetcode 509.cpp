// https://leetcode.com/problems/fibonacci-number/description/

#include<iostream>
using namespace std;


int fib(int n) {
    if(n == 0 || n == 1)
        return n;

    int count = 2;
    
    int f = 0, s = 1;
    int t;

    while(count <= n){
        t = f;
        f = s;
        s = t + s;
        count++;    
    }

    return s;

}



int main(){
    int n;
    cin >> n;

    cout << fib(n);
}



