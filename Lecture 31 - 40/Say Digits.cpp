#include<iostream>
#include<unordered_map>
using namespace std;


string numberToString(int n){
    unordered_map<int, string> numberMap = {
                                        {0,"Zero"},
                                        {1,"One"},
                                        {2,"Two"},
                                        {3,"Three"},
                                        {4,"Four"},
                                        {5,"Five"},
                                        {6,"Six"},
                                        {7,"Seven"},
                                        {8,"Eight"},
                                        {9,"Nine"},  
                                    };
    return numberMap[n];
}


void sayDigit(int n){
    if(n == 0) return;

    sayDigit(n/10);

    cout << numberToString(n%10) << " ";
}

int main(){
    int n;
    cin >> n;

    sayDigit(n);
}