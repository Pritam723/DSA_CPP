#include<iostream>
using namespace std;

void reverse(char str[], int length){
    int start = 0, end = length - 1;
    while(start < end){
        swap(str[start++], str[end--]);
    }
}

int getLength(char str[]){
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        count++;
        i++;
    }
    return count;    
};

int main(){
    char name[10];
    cin >> name;

    cout << "Your name is : " << name << endl;
    cout << "Length of your name is : " << getLength(name) << endl;
    reverse(name, getLength(name));
    cout << "Your reversed name is : " << name << endl;


}