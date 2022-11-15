// https://leetcode.com/problems/count-primes/

#include<iostream>
#include<vector>
using namespace std;



int countPrimes(int n) {
    if(n <= 2) return 0; // Must handle this case otherwise out of bound exception.
    int count = 0;
    vector<bool> ans(n,true);
    ans[0] = ans[1] = false; // Must add this line, otherwise our Sieve array is wrong.
    for(int i = 2; i < n; i++){
        if(ans[i] == false) continue;
        for(int j = i + i; j < n; j = j + i){
            ans[j] = false;
        }
        count++;
    }
    return count;
}



int countPrimes(int n) {
    if(n <= 2) return 0; // Must handle this case otherwise out of bound exception.
    int count = 0;
    vector<bool> ans(n,true);
    ans[0] = ans[1] = false; // Must add this line, otherwise our Sieve array is wrong.
    for(int i = 2; i*i < n; i++){
        if(ans[i] == false) continue;
        for(int j = i * i; j < n; j = j + i){
            ans[j] = false;
        }
        count++;
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    cout << countPrimes(N);
}