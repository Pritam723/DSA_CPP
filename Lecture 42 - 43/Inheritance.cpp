#include<iostream>
using namespace std;

class Human{
    public:
    int height = 5;
};

class Male : private Human{

    int age;
};

int main(){

    Human h1;
    cout << h1.height; // This is fine.

    Male m1;
    // cout << m1.height; // This is not fine.

    return 0;
}

