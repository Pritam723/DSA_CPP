#include<iostream>
using namespace std;

int cal_ncr(int n, int r){

    int i = n-r+1;
    int j = 1;
    int numerator = 1;
    int denominator = 1;

    while(i <= n){
        numerator = numerator * i;
        i++;
    }

    while(j <= r){
        denominator = denominator * j;
        j++;
    }

    return numerator/denominator;

}

int main(){
    int n, r;

    cin >> n >> r;
    // cin >> r;

    cout << cal_ncr(n, r);



    return 0;
}