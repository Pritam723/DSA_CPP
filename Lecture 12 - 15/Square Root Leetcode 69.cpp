// Leetcode 69 : Sqrt(x)
// https://leetcode.com/problems/sqrtx/

#include<iostream>
#include<math.h>
using namespace std;


int mySqrt(int x) {
    int s = 1, e = x;
    int m = s + (e-s)/2;
    if(x == 0)
        return 0;
    while(s<=e){
            
        if(m == x/m)
            return m;
        if(m > x/m)
            e = m - 1;
        else
            s = m + 1;

        m = s + (e-s)/2;
    }
    return s - 1;
}

double sqrt_Precision(int x, int precision){
    // precision = no. of digit after decimal.
    double ans;
    double integerPart = mySqrt(x);
    double square = integerPart * integerPart;
    double gran = 1;

    for(int i = 0; i < precision ; i++)
        gran = gran/10;

    while(square < x){
        integerPart = integerPart + gran;
        square = integerPart * integerPart;
    }

    return integerPart - gran;

    // But this solution will cause it to chevk much more. Ex. Say answer is 6.32
    // To reach it we need to go 32 times in our approach. But if we do what is done in video,
    // Then it takes only 3 + 2 = 5 steps. 

}


double sqrt_Precision_Sol2(int x, int precision){
    // precision = no. of digit after decimal.
    double ans = sqrt(x);
    double factor = 1;

    for(int i = 0; i < precision; i++){

        double factor = factor/10; // So, initially f is 0.1, then it is 0.01, then it is 0.001 depending on the precision.

        for(double temp = ans; temp * temp < x ; temp = temp + factor){
            ans = temp;
        }
    }
    return ans;

}


    

int main(){

    int x;
    cin >> x;

    cout << "SQRT(x) is " << sqrt_Precision_Sol2(x, 6);

    return 0;
}

