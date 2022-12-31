// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;

bool isPalindrome(Node *head)
{
    // Your code here
    // Find Middle First.
    Node *sp = head, *fp = head->next; // See, we are starting from head->next. Min nodes = 1 given no issue.
    while(fp != NULL and fp->next != NULL){
        sp = sp->next;
        fp = fp->next->next;
    }
    Node* mid = sp;
    
    Node* prev = NULL;
    Node* curr = sp->next;
    Node* forward = NULL;
    // Logic is same for both case. So no need to use if else.
    // if(fp == NULL){  // Odd no. of nodes. sp is at 4. Reverse from sp->next.
                    
    // }else{   // Even no. of nodes. sp is at 3. So, Reverse from sp->next
        
    // }
    
    // Say we have 3-2-1 starting from curr.
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    // So, after while we will have 1-2-3-NULL. And prev will point to 1. WKR.
    // So, now make mid->next = prev.
    
    mid->next = prev;
    
    // Now out LL looks like 1-2-3-4-1-2-3 or 1-2-3-1-2-3. mid is at 4 or 3.
    
    Node *left = head, *right = mid->next;
    while(right != NULL){
        if(left->data != right->data) return false;
        
        left = left->next;
        right=right->next;
    }
    return true;
}

int main(){
    Node *node1 = new Node(1);
    Node *head = node1;

    insert_at_begin(head, 0);
    insert_at_begin(head, 5);
    insert_at_begin(head, 0);
    insert_at_begin(head, 0);
    insert_at_begin(head, 1);
    printLL(head);

    cout << isPalindrome(head) << endl;


}