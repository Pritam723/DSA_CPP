// https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927

#include<iostream>
using namespace std;

void reverseString(string &str, int s , int e){

    if(s >= e) return;

    swap(str[s],str[e]);


    // Infact we can put swap after returning too. Does not affect the logic.
    reverseString(str, s+1, e-1);

}

int main(){
    string str = "abcjkshkfshke";
    int s = 0, e = str.length() - 1;

    reverseString(str,s,e);
    cout << str;
}