// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0
#include<iostream>
using namespace std;
#include<stack>

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> opStack;
    for(int i = 0; i < s.length() ; i++){
        if(s[i] >= 'a' and s[i] <= 'z'){
            continue;
        }else if(s[i] == '('){
            opStack.push(s[i]);
        }else if(s[i] == ')'){ 
            // Here if top is '(', surely it is redundant. Otherwise,
            // We must pop till we find a '('.
            // And finally again we will pop the '(' too.
            
            if(opStack.top() == '(') return true;
            else{
                while(opStack.top() != '('){
                    opStack.pop();
                }
                opStack.pop();
            }
            
            
        }else{ // So, this is +,-,* or /
            opStack.push(s[i]);
        }
    }
    return false;
}

int main(){
    string s = "((a+b))";
    cout << findRedundantBrackets(s);
}
