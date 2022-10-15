#include<iostream>
using namespace std;

/* 

i) Case constant must be int or char.
ii) If we do  ot break, then everything after matching case will be printed until next break is found.
iii) Switch can be nested. Inside Case, we can inturn switch.
iv) If Else and Switch Case can be interconverted. But in case of switch inside while loop,
    use exit() instead of break; And continue inside switch is not valid.
    To simulate Continue, simply use a blank case which does nothing.
*/

int main(){
    int num = 1;
    switch(num){

        case 1 :
            cout << "First" <<endl;
            // break;
        case 2 :
            cout << "Second" <<endl;
            // break;

        case 3 : 
            switch(num){
                    case 1 :
                        cout << "Hello";
                        //break;
                    case 2 :
                        cout << "Hi";
            }
            
            break;

        default :
            cout << "It is default case.";

    }

    return 0;
}