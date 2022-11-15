// https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633
// https://leetcode.com/problems/valid-palindrome/

/*
ASCII value for a-z is 97 to 122
A-Z is 65 to 90
0-9 is 48 to 57
Or use int(ch) to get the values.
*/

#include<iostream>
#include<vector>
using namespace std;

bool isAlphaNumeric(char ch){
    // We have already made a lowercase copy of the String.
    if((int(ch) >= 97 && int(ch) <= 122) or (int(ch) >= 48 && int(ch) <= 57))
        return true;
    return false;
}

bool isPalindrome(string s) {
    
    for(int i = 0; i < s.size() ; i++){
        if(int(s[i]) >= 65 && int(s[i]) <= 90)
            s[i] = s[i] + 32; // Making it lower case
    }

    int  start = 0, end = s.size() - 1;
    while(start < end){
        if(!isAlphaNumeric(s[start])){
            start++;
            continue;
        }
        if(!isAlphaNumeric(s[end])){
            end--;
            continue;
        }
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int main(){
    string str = "A man, a plan, a canal: Panama"; 
    cout << isPalindrome(str);
}