#include<iostream>
using namespace std;

int main(){

    int a;
    cout<<"Input a number : "<<endl;

    cin>>a;

    int sum = 0;

    int i = 0;
    
    while(i <= a){

        sum = sum + i;
        i = i + 1;
    }

    cout << sum ;
    return 0;

}