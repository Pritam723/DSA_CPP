// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
#include<iostream>
using namespace std;


string removeOccurrences(string s, string part) {
    string ans = s;
    int m = part.length();
    while(true){
        int idx = ans.find(part);
        if(idx >= ans.length()) return ans;
        ans.erase(idx, m);
    }
}


string removeOccurrencesSol2(string s, string part) {
    string ans = "";
    int m = part.length();
    for(char ch : s){
        ans.push_back(ch);
        if(ans.length() >= m && ans.substr(ans.length() - m) == part){
            int count = 0;
            while(count < m){
                ans.pop_back();
                count++;
            }
        }
    }
    return ans;
}


int main(){
    string s = "cskpygkpygkivtlqoocssnextkqzjpycbylkaondsk"
;
    string part = "kpygkivtlqoocssnextkqzjpycbylkaonds";

    cout << removeOccurrencesSol2(s,part);
}