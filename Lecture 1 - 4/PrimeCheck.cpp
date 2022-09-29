#include<iostream>
using namespace std;

int main(){

    int N;
    cout << "Give a number to check" <<endl;
    cin >> N;
    cout << "Your input is : " << N << endl;

    int i = 2;
    bool flag = true;
    
    while(i < N){

        if(N % i == 0){
            cout << "Your number is not prime" << endl;
            flag = false; 
            break;
        }
        i++;
    }

    if(flag){

        cout << "Your number is prime" << endl;

    }

    return 0;
}