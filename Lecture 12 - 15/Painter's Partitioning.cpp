#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* 
A : No. of painter. Each takes B unit of time to paint 1 unit of Board. So, if Board length is 5 unit, B = 7, then to paint it we need 35 unit of time.
C is an array of size N. N = Number of boards, C[i] = represents length of ith board.
*/

bool isSolPossible(int A, vector<int> &C, int N, int val){
    
    int i = 0;
    
    while(A > 0){
        
        int partSum = 0;
        
        while(partSum + C[i] <= val){        
            partSum = partSum + C[i];
            i = i + 1;
            if(i == N) return true;
        }
       
        A = A - 1;
    }
    
    return false;
    
    
}



int paint(int A, int B, vector<int> &C) {

    // Surely, answer will be b/w 0 and sum(C)
    long long int ans;

    if(A > C.size()) {
        ans = *max_element(C.begin(), C.end());
        return ((ans % 10000003) * (B % 10000003)) % 10000003;

    }

        int s = 0, e = 0;
    
        for(int i = 0; i < C.size() ; i++){
            e = e + C[i];
        }
        
        int m = s + (e-s)/2;
        while(s <= e){
            if(isSolPossible(A,C,C.size(),m)){
                ans = m;
                e = m - 1;
            }     
            else
                s = m + 1;
            
            m = s + (e-s)/2;
        }
        return ((ans % 10000003) * (B % 10000003)) % 10000003;
}





int main(){

    int A = 3;
    int B = 10;
    vector<int> C = { 640, 435, 647, 352, 8, 90, 960, 329, 859 };

    cout << paint(A, B,C)<<endl;
    // int i;
    // for(i = 0; i <= 4320 ; i++){
    //     if(isSolPossible(A,C,C.size(),i))
    //         break;
    // }
    // cout << i;

    return 0;
}