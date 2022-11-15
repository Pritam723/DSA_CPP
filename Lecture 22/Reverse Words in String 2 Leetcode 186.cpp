// https://leetcode.com/problems/reverse-string/


#include<iostream>
#include<vector>
using namespace std;

void reversePartial(vector<char>& str, int start, int end){
    while(start < end){
        swap(str[start++],str[end--]);
    }
}

void reverseWords(vector<char>& str) {
   int start = 0;
   int n = str.size();
   for(int i = 0; i < n; i++){
        
        if(str[i] == ' '){
            reversePartial(str, start, i-1);
            start = i+1;
            continue;
        }
   }
    
    reversePartial(str, start, n-1);

    reversePartial(str, 0, n-1);
}

void printArray(vector<char> vec){
    for(char ch : vec){
        cout << ch << " ";
    }
}

int main(){
    vector<char> name = {'m','y',' ','n','a','m','e', ' ', 'i','s'};
    reverseWords(name);
    printArray(name);

}