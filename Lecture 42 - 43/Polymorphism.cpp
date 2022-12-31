#include<iostream>
using namespace std;

class Employee{
    public:
    int salary;
    
    int operator+ (Employee emp){
        return this->salary + emp.salary;
    }
};


int main(){

    Employee e1;
    Employee e2;
    e1.salary = 20;
    e2.salary = 30;

    cout << e1 + e2 << endl;
    return 0;
}

