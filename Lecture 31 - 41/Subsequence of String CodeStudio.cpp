// https://leetcode.com/problems/subsets/
#include<iostream>
#include<vector>
using namespace std;


void solution(string str, string output, int index, vector<string> &ans){
    if(index >= str.length()){
        if(output.length() != 0)
            ans.push_back(output);
        return;
    }

    // Excluding str[i] character
    solution(str, output, index + 1, ans);
    
    // Including str[i] character
    
    output.push_back(str[index]);
    solution(str, output, index+1, ans);

}

vector<string> subsequences(string str){
	
    vector<string> ans;
    string output = "";
    int index = 0;

    solution(str, output, index, ans);

    return ans;    
	
}


int main(){
    string str = "abc";
    vector<string> ans1;
    ans1 = subsequences(str);

    for(auto s : ans1){
        cout << s << endl;
    }

}
