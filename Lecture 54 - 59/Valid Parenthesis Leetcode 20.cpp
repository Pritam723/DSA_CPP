// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104
// https://leetcode.com/problems/valid-parentheses/description/

#include<iostream>
using namespace std;
#include<stack>
#include<map>

char getClosure(char ch){
    map<char, char> ch_map;
    ch_map[')'] = '(';
    ch_map['}'] = '{';
    ch_map[']'] = '[';

    return ch_map[ch];
}

bool isValid(string s) {
    if(s.empty()) return true;
    stack<char> charStack;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' or s[i] == '{' or s[i] == '['){
            charStack.push(s[i]);
        }
        else{
            if(charStack.empty() or (charStack.top() != getClosure(s[i]))) return false;
            charStack.pop();
        }
    }
    
    return charStack.empty();
}

int main(){
    string s = "]";
    cout << isValid(s);
}