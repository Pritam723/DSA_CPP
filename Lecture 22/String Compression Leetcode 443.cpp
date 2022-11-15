// https://leetcode.com/problems/string-compression/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string my_to_string(int count){
    string scount;
    while(count != 0){
        char ch = (count%10) + '0' - 0;
        scount.push_back(ch);
        count = count/10;
    }
    reverse(scount.begin(), scount.end()); 
    return scount;
}


int compress(vector<char>& s) {
    int lastIdx = 0, count = 1;
    char lastChar = s[0];
    
    for(int i = 1; i < s.size() ; i++){
        if(s[i] == lastChar) count++;
        else{
            if(count != 1){
                string scount = to_string(count);
                for(char ch : scount){
                    s[++lastIdx] = ch;
                }
            }
            s[++lastIdx] = s[i];
            lastChar = s[i];
            count = 1;
        }
    }
    if(count != 1){
        string scount = my_to_string(count);
        for(char ch : scount){
            s[++lastIdx] = ch;
        }
    }

    return lastIdx + 1;
}


int main(){
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int n = compress(chars);
    for(int i = 0; i< n; i++){
        cout << chars[i];
    }

}