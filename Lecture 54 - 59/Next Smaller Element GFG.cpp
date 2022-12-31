// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581
// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;



vector<int> help_classmate_altSol(vector<int> arr, int n) { 
    // Your code goes here
    vector<int> ans(n,0);
    stack<int> nse;
    
    nse.push(-1);
    
    for(int i = arr.size() - 1; i >= 0; i--){
        int curr = arr[i];        
        while(nse.top() >= curr){
            nse.pop();
        }
        // Surely now nse.top() is < curr
        ans[i] = nse.top();
        nse.push(curr);
        
    }
    // reverse(ans.begin(), ans.end()); // No need to reverse anymore.
    return ans;
}

vector<int> help_classmate(vector<int> arr, int n) { 
    // Your code goes here
    vector<int> ans;
    stack<int> nse;
    
    nse.push(-1);
    
    for(int i = arr.size() - 1; i >= 0; i--){
        int curr = arr[i];
        
        if(nse.top() < curr){
            ans.push_back(nse.top());
            nse.push(curr);
        }else{
            while(nse.top() >= curr){
                nse.pop();
            }
            // Surely now nse.top() is < curr
            ans.push_back(nse.top());
            nse.push(curr);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {2,1,4,3};
    vector<int> ans = help_classmate(arr, arr.size());
    for(int elem : ans){
        cout << elem << endl;
    }
}