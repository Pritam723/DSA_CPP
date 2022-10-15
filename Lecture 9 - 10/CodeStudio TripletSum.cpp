#include <bits/stdc++.h>
#include<iostream> 
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here. So we should return a vector of vectors. Each vector inside should have 2 integers.
    
    vector<vector<int>> res;
    
    int i = 0;
    int j = arr.size() - 1;
    
    int lastChecked = arr[0] - 1;
    
    while(i < j){
        
        if((arr[i] + arr[j] == s) && (arr[i] != lastChecked)){
            lastChecked = arr[i];
            vector<int> temp = {arr[i], arr[j]};
            res.push_back(temp);
            i++;
            j--;    
        }else if(arr[i] + arr[j] > s){
            j--;
        }else{
            i++;
        }
    }

    return res;
}




vector<vector<int>> findTriplets(vector<int> arr, int n, int S) {
	// Write your code here.
    int size = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    
    int lastChecked = arr[0] - 1;
    for(int i = 0; i < size - 2; i++){
        
        if(arr[i] != lastChecked){
            lastChecked = arr[i];
            vector<int> vectorToSend(arr.begin() + i + 1, arr.end()); 
            vector<vector<int>> res = pairSum(vectorToSend, S - arr[i]);
            for(auto elem : res){
                elem.push_back(arr[i]);
                ans.push_back(elem);
            }
        }
             
    }
    
    return ans;
}

int main(){

    vector <int> arr = {1, 2, 3, 1, 2, 3};
    int s = 5;
    sort(arr.begin(), arr.end());
    vector<vector<int>> res = findTriplets(arr, arr.size(), s);
    // vector<vector<int>> res = pairSum(arr, s);

    cout << res.size() << endl;
    for(auto elem : res){
        for(auto x : elem){
            cout << x << " ";
        }
        cout << endl; 
    }


    return 0;
}