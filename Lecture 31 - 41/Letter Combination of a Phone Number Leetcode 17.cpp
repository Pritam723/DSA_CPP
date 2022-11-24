#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// vector<string> multiplyStrChar(vector<string> strVec, vector<char> charVec){
    
//     vector<string> ans;

//     if(strVec.size() == 0){
//         for(char ch : charVec){
//             string str;
//             str = str + ch;
//             ans.push_back(str);
//         }
//         return ans;
//     }
    
//     for(int i = 0; i < strVec.size(); i++){
//         for(int j = 0; j < charVec.size(); j++){
//             string str = strVec[i];
//             str.push_back(charVec[j]);
//             ans.push_back(str);
//         }
//     }
//     return ans;
// }

// vector<char> getNumberMap(char ch){
    
//     vector<char> numberToString;
//     unordered_map<char,string> numberMap = {
//         {'2', "abc"},
//         {'3', "def"}
//     };

//     for(int i = 0; i < numberMap[ch].length(); i++){
//         numberToString.push_back(numberMap[ch][i]);
//     }

//     return numberToString;
// }

// void solution(string digits,int index, vector<string> &ans){
//     if(index >= digits.length()) return;
    
//     // Otherwise process
//     // Get the corresponding characters. '2' --> {'a', 'b', 'c'}
//     vector<char> numberToString = getNumberMap(digits[index]);

//     // Now in the existing ans, multiply each string with each character of this vector. {a,b} * {c,d} = {ac,ad,bc,bd} like this.
//     ans = multiplyStrChar(ans,numberToString);

//     solution(digits, index+1, ans);
// }

// vector<string> letterCombinations(string digits) {
    
//     vector<string> ans = {};
//     int index = 0;
//     solution(digits,index,ans);
//     return ans;
// }

string getNumberMapBackTracking(char ch){
    
    unordered_map<char,string> numberMap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    return numberMap[ch];
}

void solutionBackTracking(string digits,string output, int index, vector<string> &ans){
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }
    string numberStr = getNumberMapBackTracking(digits[index]);

    for(char ch : numberStr){
        output.push_back(ch);
        solutionBackTracking(digits,output,index + 1,ans);
        output.pop_back();
        // We must pop() while doing the next for() iteration.
    }
}

vector<string> letterCombinationsBackTracking(string digits) {
    vector<string> ans = {};
    if(!digits.length()) return ans;

    string output = "";
    int index = 0;
    solutionBackTracking(digits,output,index,ans);
    return ans;
}

int main(){
    vector<string> ans;
    string inputString = "23";
    ans = letterCombinationsBackTracking(inputString);
    for(string str : ans){
        cout << str << endl;
    }

    return 0;
}