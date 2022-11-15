#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<bool> makeSieve(int n){
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    for(int i = 0; i*i <= n; i++){
        if(sieve[i] == false) continue;
        for(int j = i*i; j <= n; j=j+i){
            sieve[j] = false;
        }
    }
    return sieve;
}


int countPrimes(int L, int R) {
    // code here
    if(L < 2) L = 2;
    if(R < 2) return 0;
    
    vector<bool> sieve = makeSieve(sqrt(R));
    for(bool x : sieve){
        cout << x << " ";
    }
    
    vector<bool> dummy(R-L+1,true);
    
    for(int i = 2; i <= sieve.size(); i++){
        
        if(sieve[i] == false) continue;
        
        int firstMultiple = (L/i)*i;
        if(firstMultiple < L) firstMultiple = firstMultiple + i;
        
        for(int j = max(i*i, firstMultiple); j <= R ; j = j+i){
            dummy[j - L] = false;
        }
    }
    int count = 0;
    for(int k = L; k <= R; k++){
        if(dummy[k-L] == true){
            count++;
            // cout << k << " ";
        }
    }
    return count;
}


int main(){
    int L,R;
    cin >> L >> R;
    cout << countPrimes(L,R);
}