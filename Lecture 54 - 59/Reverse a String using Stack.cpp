#include<iostream>
using namespace std;
#include<stack>

string reverseString(string str){
    string ans = "";
    stack<char> s;

    for(int i = 0; i < str.length() ; i++){
        s.push(str[i]);
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main(){
    string str = "Hello";
    cout << reverseString(str) << endl;
}