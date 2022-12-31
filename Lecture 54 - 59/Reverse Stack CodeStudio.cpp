#include<iostream>
using namespace std;
#include<stack>


void insert_at_bottom(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int topElem = myStack.top();
    myStack.pop();
    insert_at_bottom(myStack, x);
    myStack.push(topElem);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()) return;
    int topElem = stack.top();
    stack.pop();
    reverseStack(stack);
    insert_at_bottom(stack, topElem);
}

int main(){
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    while(!myStack.empty()){
        cout << myStack.top() << endl;
        myStack.pop();
    }
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    reverseStack(myStack);
    while(!myStack.empty()){
        cout << myStack.top() << endl;
        myStack.pop();
    }
}