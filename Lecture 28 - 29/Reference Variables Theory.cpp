#include<iostream>
using namespace std;

int& fun(int x){
    int y = 10;
    int& ans = y;
    return ans;
}

int main(){

    int num = 5;
    fun(num);
    return 0;
}