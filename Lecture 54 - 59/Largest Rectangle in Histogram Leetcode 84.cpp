#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getPseIndices(vector<int> arr, int n){
    vector<int> ans;
    stack<int> pseStack;
    pseStack.push(-1);
    for(int i = 0; i < n; i++){
        int curr = arr[i];
        int idx = pseStack.top();
        if(idx == -1 or arr[idx] < curr){
            ans.push_back(idx);
            pseStack.push(i);
        }else{
            while(idx != -1 and arr[idx] >= curr){
                pseStack.pop();
                idx = pseStack.top();
            }
            ans.push_back(idx);
            pseStack.push(i);
        }
    }
    return ans;
}


vector<int> getNseIndices(vector<int> arr, int n){
    vector<int> ans;
    stack<int> nseStack;
    nseStack.push(n);
    for(int i = n-1 ; i>=0 ; i--){
        int curr = arr[i];
        int idx = nseStack.top();
        if(idx == n or arr[idx] < curr){
            ans.push_back(idx);
            nseStack.push(i);
        }else{
            while(idx != n and arr[idx] >= curr){
                nseStack.pop();
                idx = nseStack.top();
            }
            ans.push_back(idx);
            nseStack.push(i);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> pseIndices = getPseIndices(heights, n);
        vector<int> nseIndices = getNseIndices(heights, n);
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int area = heights[i] * (1 + (i - pseIndices[i] - 1) + (nseIndices[i] - i - 1));
            if(area > maxArea) maxArea = area;
        }
        return maxArea;
    }


int main(){
    vector<int> arr = {2,1,5,6,2,3};
    // // vector<int> ans = getPseIndices(arr, arr.size());
    // for(int elem : ans){
    //     cout << elem << endl;
    // }

    cout << largestRectangleArea(arr) << endl;
}