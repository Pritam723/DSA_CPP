// https://leetcode.com/problems/permutation-in-string/

#include<iostream>
#include<array>
using namespace std;

bool isAllZero(array<int,26> arr){
    for(int elem : arr){
        if(elem != 0)
            return false;
    }
    return true;
}


bool checkInclusion(string s1, string s2) {
    array<int, 26> countMap = {0};
    int  m = s1.length(), n = s2.length();
    if(m > n) return false; //If we do't do this, we get error in 2nd for() loop. We try to access s2[m] but m > s2.length() i.e., m > n. 
    for(char ch : s1){
        int idx = ch - 'a';
        countMap[idx]++;
    }

    for(int i = 0; i < m; i++){
        int idx = s2[i] - 'a';
        countMap[idx]--;
    }
    
    if(isAllZero(countMap)) return true;


    for(int i = m, j = 0; i < n ; i++,j++){
        int incomingCharIdx = s2[i] - 'a';
        int outGoingCharIdx = s2[j] - 'a';
        countMap[outGoingCharIdx]++;
        countMap[incomingCharIdx]--;
        if(isAllZero(countMap)) return true;
    }



    return false;
}

int main(){
    string s1 = "ab" , s2 = "a";
    cout << checkInclusion(s1,s2);

}