// https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927

#include<iostream>
using namespace std;

string getBinaryRep(int N){

    string s;

    if(N == 0) return "0";
    if(N == 1) return "1";

    s = getBinaryRep(N >> 1) + to_string(N & 1);

    return s;
}


bool checkPalindrome(string str, int s, int e){
    if(s >= e) return true;
    if(str[s] != str[e]) return false;

    return checkPalindrome(str,s+1,e-1);
}

int main(){
    int N = 7;
    string str = getBinaryRep(N);
    cout << checkPalindrome(str, 0 , str.length() - 1);
}