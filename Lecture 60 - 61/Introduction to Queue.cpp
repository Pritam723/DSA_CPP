// Simple Queue Implementation
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0

#include <bits/stdc++.h> 
class Queue {

public:
    int size = 10000;
    int *arr;
    int qfront, qrear;
    
public:
    Queue() {
        // Implement the Constructor
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (qfront == qrear);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(qrear == size) return;
        arr[qrear] = data;
        qrear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(this->isEmpty()) return -1;
        int itemToReturn = arr[qfront];
        qfront++;
        // Now if front and rear meets, i.e. the array has become empty
        // then simply reset them
        if(this->isEmpty()){
            qfront = 0;
            qrear = 0;
        }
        return itemToReturn;
    }

    int front() {
        // Implement the front() function
        if(this->isEmpty()) return -1;
        return arr[qfront];
    }
};