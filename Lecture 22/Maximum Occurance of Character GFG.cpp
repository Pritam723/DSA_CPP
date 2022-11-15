// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
#include<iostream>
using namespace std;

char getMaxOccuringChar(string str)
{
    // Your code here
    int countMap[128] = {0};
    for(char ch : str){
        countMap[ch]++;
    }
    
    int maxOccCharIdx = 0;
    for(int i = 1; i < 128; i++){
        cout << countMap[i] << " ";
        if(countMap[i] > countMap[maxOccCharIdx])
            maxOccCharIdx = i;
    }
    
    return maxOccCharIdx; // Don't send countMap[maxOccCharIdx], that's wrong.
    // Say maxOccCharIdx = index of 'l' = 76. So, countMap[76] will be count of 'l' actually. char(2) = wrong answer.
}


int main(){

    cout << getMaxOccuringChar("hello");

}