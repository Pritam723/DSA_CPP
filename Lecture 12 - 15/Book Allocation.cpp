// https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574

#include <bits/stdc++.h> 
#include<vector>
using namespace std;

bool isPossibleSol(vector<int> arr, int partition, int value){
    int i = 0;
    while(partition > 0){
        int partSum = 0;
        while(partSum + arr[i] <= value){
            partSum = partSum + arr[i];
            i = i + 1;
            if(i == arr.size()) return true;
        }
        partition = partition - 1;
    }
    return false;
}



long long ayushGivesNinjatest(int n, int M, vector<int> time) 
{	
	// Write your code here.
    if(M > time.size()) return -1;
    
    int s = 0, e = accumulate(time.begin(), time.end(), 0);
    int m = s + (e-s)/2;
    int ans;
    if(n == 1) return e;
    
    while(s <= e){
        if(!isPossibleSol(time,n,m))
            s = m + 1;
        else{
            ans = m;
            e = m - 1;
        }
        
        m = s + (e-s)/2;
    }
    return ans;
}

int main(){

    vector<int> vec = {12,34,67,90};
    for(int i = 0; i < accumulate(vec.begin(), vec.end(),0) ; i++){
        cout << isPossibleSol(vec, 5, i);
        // if(isPossibleSol(vec, 5, i)){
        //     cout << endl << i << endl;
        //     break;
        // }
    }
    // cout << ayushGivesNinjatest(2, vec.size(), vec);

    return 0;
}