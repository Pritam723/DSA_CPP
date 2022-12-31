// https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232
// https://practice.geeksforgeeks.org/problems/circular-linked-list/1

#include "LinkedListCode.cpp"
#include<iostream>
#include<map>
using namespace std;

bool isCircular(Node* head){
    // Write your code here.
    map<Node*, bool> nodeMap;
    if(head == NULL) return true;
    Node *temp = head->next;
    while(temp != NULL){
        if(temp == head) return true;
        if(nodeMap.count(temp)) return false;
        nodeMap[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){

    Node* node1 = new Node(80);
    Node *head = node1;
    insert_at_begin(head,70);
    insert_at_begin(head,60);
    insert_at_begin(head,50);

    // node1 is last node now.

    node1->next = head->next; //Forming a cycle. But yet not circular.
    cout << isCircular(head) << endl;

    node1->next = head; //Forming a cycle and making it circular.
    cout << isCircular(head) << endl;


}