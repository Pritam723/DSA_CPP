#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> vec = {10,20,20,30,40,50,55,60,60,70,80};

    auto it = lower_bound(vec.begin() + 3, vec.begin() + 8, 72);
    cout << "The pointer is pointing to " << *(it+1);
    return 0;
}