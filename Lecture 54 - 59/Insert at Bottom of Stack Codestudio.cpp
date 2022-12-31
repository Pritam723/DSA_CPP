// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

#include<iostream>
using namespace std;
#include<stack>

void solution(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    int topElem = myStack.top();
    myStack.pop();
    solution(myStack, x);
    myStack.push(topElem);
}

stack<int> pushAtBottom(stack<int> myStack, int x) 
{
    // Write your code here.
    solution(myStack, x);
    return myStack;
}

int main(){
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack = pushAtBottom(myStack, 0);
    while(!myStack.empty()){
        cout << myStack.top() << endl;
        myStack.pop();
    }
}