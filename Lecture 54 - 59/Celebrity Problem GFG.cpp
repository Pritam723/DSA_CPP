// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


int celebrity_bruteforce(vector<vector<int> >& M, int N) 
{
    // code here 
    for(int i = 0; i < N ; i++){
        bool isCeleb = true;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            
            isCeleb = isCeleb & (!M[i][j]) & (M[j][i]);
        }
        if(isCeleb) return i;
    }
    return -1;
}

bool knows(vector<vector<int>>& M, int A, int B){
    if(M[A][B] == 1) return true;
    return false;
}

int celebrity(vector<vector<int>>& M, int N) 
{
    stack<int> potentialCeleb;
    for(int i = 0; i < N; i++){
        potentialCeleb.push(i);
    }
    while(potentialCeleb.size() != 1){
        int A = potentialCeleb.top();
        potentialCeleb.pop();
        int B = potentialCeleb.top();
        potentialCeleb.pop();

        if(knows(M,A,B)){  // Passing by reference, so no extra space is required.
            // If A knows B, A can not be a celebrity.
            potentialCeleb.push(B);
        }else{
            // If A does not know B, B can not be a celebrity.
            potentialCeleb.push(A);
        }
    }
    // Now stack has one element only.
    int lastPerson = potentialCeleb.top();
    // Say potetial top is 1. So I must check row 1 and col 1. (10,11,12 should be all 0 and 01,11,21 should be all 1) Ignore diagonal.
    bool isCeleb = true;
    for(int i = 0; i < N; i++){
        if(i == lastPerson) continue; // Ignoring diagonals.
        isCeleb = isCeleb & M[i][lastPerson] & !M[lastPerson][i];
    }

    if(isCeleb) return lastPerson;
    return -1;

}

int main(){
    int N = 3;
    vector<vector<int>> rel = {{0,1,0},{0,0,0},{0,1,0}};
    cout << celebrity_bruteforce(rel, N) << endl;
    cout << celebrity(rel, N) << endl;

}