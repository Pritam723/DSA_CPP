// https://leetcode.com/problems/reverse-nodes-in-k-group/
// https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0

#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;
/*
Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* prevHead = head;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = k; // Because we need to pass k to next call.

    // cout << endl << " Recursion" << endl;

    if(curr == NULL) return NULL;
    // cout << endl << " thurth val " << (k > 0)  << endl;
    // cout << endl << " thurth val2 " << (curr != NULL)  << endl;

    while((count > 0) && (curr != NULL)){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count--;
        // cout << endl << " While" << endl;

    }
    Node *headSP = kReverse(curr, k); // Chota head.
    prevHead->next = headSP;
    // cout << endl << " just before returning prev" << prev->data<< endl;

    return prev;
}

*/

Node* reverseKGroup(Node* head, int k, int lengthToCover) {
    // Write your code here.
    Node* prevHead = head;
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = k; // Because we need to pass k to next call.

    // cout << endl << " Recursion" << endl;

    if(curr == NULL or k > lengthToCover) return curr;
    // cout << endl << " thurth val " << (k > 0)  << endl;
    // cout << endl << " thurth val2 " << (curr != NULL)  << endl;

    while((count > 0) && (curr != NULL)){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count--;
        // cout << endl << " While" << endl;

    }
    Node *headSP = reverseKGroup(curr, k, lengthToCover-k); // Chota head.
    prevHead->next = headSP;
    // cout << endl << " just before returning prev" << prev->data<< endl;

    return prev;
    
}


int main(){
    Node *node1 = new Node(80);
    Node *head = node1;

    insert_at_begin(head, 70);
    insert_at_begin(head, 60);
    insert_at_begin(head, 50);
    insert_at_begin(head, 40);
    insert_at_begin(head, 30);
    insert_at_begin(head, 20);
    insert_at_begin(head, 10);

    printLL(head);
    int lengthToCover = lengthLL(head);
    cout << "start" << lengthToCover << endl;
    // Node *hh = kReverse(head, 3);
    Node *hh = reverseKGroup(head, 3, lengthToCover);

    printLL(hh);

}