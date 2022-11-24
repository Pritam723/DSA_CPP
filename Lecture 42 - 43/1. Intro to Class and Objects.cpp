#include<iostream>
using namespace std;

class Hero{
    
    int health;
    char level;
    
    public:
    
    Hero(){
        cout << "Default Constructor" << endl;
    }

    Hero(int health){
        this->health = health;
    }

    Hero(int health, char level){
        this->health = health;
        (*this).level = level; // Both fine.
    }
    
    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char l){
        level = l;
    }

};

int main(){

    Hero goku(70, 'A');

    // goku.setHealth(70);
    // goku.setLevel('A');

    cout << goku.getHealth() << endl;
    cout << goku.getLevel() << endl;

    return 0;
}