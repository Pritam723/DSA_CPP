// https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186



#include<iostream>
#include<vector>
using namespace std;

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    vector<int> ans(max(n,m),0);
    int i = n-1;
    int j = m-1;
    int k = max(n,m) - 1;
    int sum = 0;
    int digit = 0;
    int carry = 0;

    
    while(k >= 0){
        sum = (i < 0 ? 0 : a[i]) + (j < 0 ? 0 : b[j]) + carry;
        digit = sum % 10;
        carry = sum/10;
        ans[k] = digit;
        i--;
        j--;
        k--;
    }
    if(carry != 0)
        ans.insert(ans.begin(), carry);

    return ans;
}


int main(){
   
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {9,9,9,9,9};

    for(int elem : findArraySum(arr1,arr1.size(),arr2,arr2.size())){
        cout << elem << " ";
    }
    
    return 0;
}


