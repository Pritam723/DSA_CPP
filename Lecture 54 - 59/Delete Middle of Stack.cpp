// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0
// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

#include<iostream>
using namespace std;
#include<stack>
#include<vector>

void deleteMiddleRecursiveSol(stack<int>&inputStack, int N, int count){
    
    if(count == (N+1)/2) {
        inputStack.pop();
        return;
    }

    int topElem = inputStack.top();
    inputStack.pop();
    count = count + 1;

    deleteMiddleRecursiveSol(inputStack, N, count);
    inputStack.push(topElem);

}

// void deleteMiddle(stack<int>&inputStack, int N){
	
//    // Write your code here
    
//     int midIdx = (N+1)/2;
//     int restElem = N - midIdx;
//     vector<int> vec(restElem, 0);
    
//     for(int i = 0; i < restElem; i++){
//         cout << "Loop1";
//         vec[i] = inputStack.top();
//         inputStack.pop();
//     }
    
//     // Popping middle item.
//     inputStack.pop();
    
//     // Pushing back the top items.
//     for(int i = restElem - 1; i >= 0 ; i--){
//         cout << "loop2";
//         inputStack.push(vec[i]);
//     }
//     cout << endl;
// }

int main(){
    int N = 3; // stack size is N+1
    stack<int> myStack;
    myStack.push(8);
    myStack.push(7);
    myStack.push(6);
    myStack.push(5);
    int count = 0;

    deleteMiddleRecursiveSol(myStack, N, count);
    while(!myStack.empty()){
        cout << myStack.top() << endl;
        myStack.pop();
    }

}