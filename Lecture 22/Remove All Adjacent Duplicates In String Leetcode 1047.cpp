// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include<iostream>
using namespace std;


string removeDuplicates(string s) {
    string ans;
    ans.push_back(s[0]);
    int top = 0;
    
    for(int i = 1; i < s.length(); i++){
        if(top == -1 || ans[top] != s[i]){
            ans.push_back(s[i]);
            top++;
        }else{
            ans.pop_back();
            top--;
        }
    }
    return ans;
}

int main(){
    string s = "abbaca";
    cout << removeDuplicates(s);
}