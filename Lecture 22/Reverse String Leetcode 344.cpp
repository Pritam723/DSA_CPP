// https://leetcode.com/problems/reverse-string/


#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& str) {
    int s = 0, e = str.size() - 1;
    while(s < e){
        swap(str[s++], str[e--]);
    }
}

void printArray(vector<char> vec){
    for(char ch : vec){
        cout << ch << " ";
    }
}

int main(){
    vector<char> name = {'h','e','l','l','o'};
    reverseString(name);
    printArray(name);

}