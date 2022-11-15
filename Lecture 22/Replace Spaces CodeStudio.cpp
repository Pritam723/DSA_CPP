// https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172

#include<iostream>
using namespace std;

string replaceSpaces(string &str){
	// Write your code here.
    string ans = "";
    for(char ch : str){
        // cout << ch << " ";
        if(ch == ' '){
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
            continue;
        }
        ans.push_back(ch);
    }
    return ans;
}


string replaceSpacesSol2(string &str){
	// Write your code here.
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            str.insert(i, "@40");
            str.erase(i+3,1);

        }
    }
    return str;
}

int main(){
    string s = "Hi there";
    // string s1 = replaceSpacesSol2(s);
    // cout << s1;
    s.insert(2,"@40");
    s.erase(5,1);
    cout << s;
}