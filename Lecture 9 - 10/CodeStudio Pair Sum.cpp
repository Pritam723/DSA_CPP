// https://www.codingninjas.com/codestudio/problems/pair-sum_697295

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here. So we should return a vector of vectors. Each vector inside should have 2 integers.
    
    vector<vector<int>> ans;
    
    int i = 0;
    int j = i + 1;
//     sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1 ; i++){
        
        for(int j = i + 1; j < arr.size() ; j++){
            
            if(arr[i] + arr[j] == s){
                vector<int> sPair = {min(arr[i], arr[j]) , max(arr[i], arr[j])};
                ans.push_back(sPair);
             }
                
        }
        
    }
    // Or if we don't sort the vector initially, we can sort the ans at last. WKT, default behavior is non-decreasing. So, it works.
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){

    vector <int> arr = {2, -3, 3, 3, -2};
    int s = 0;

    vector<vector<int>> res = pairSum(arr, s);

    for(auto elem : res){
        for(auto x : elem){
            cout << x << " ";
        }
        cout << endl; 
    }

    return 0;
}