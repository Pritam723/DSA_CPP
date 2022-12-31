// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=1

#include<iostream>
using namespace std;
#include<stack>

int findMinimumCost(string str) {
  // Write your code here
    if(str.length() % 2 == 1) return -1;
    
    int a = 0, b = 0;
    stack<char> s;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '{'){
            s.push(str[i]);
        }else{ // str[i] == '}', so we check stack top.
            if(!s.empty() and s.top() == '{')
                s.pop(); // So, we got a valid pattern.
            else
                s.push(str[i]);
        }
    }
    // After this, the stack will only have the invalid part of the string.
    while(!s.empty()){
        if(s.top() == '{') b++;
        else a++;
        s.pop();
    }
    return (a+1)/2 + (b+1)/2;
}

int main(){
    string s = "{{{}}{";
    cout << findMinimumCost(s);
}