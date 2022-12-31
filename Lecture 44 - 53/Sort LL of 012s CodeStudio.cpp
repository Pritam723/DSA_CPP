// https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0

#include "LinkedListCode.cpp"
#include<iostream>
#include<map>
using namespace std;

void insert_at_tail(Node* &tail, Node* nodeToAdd){
    // No need to check if head is NULL, coz we are using dummy node.
    tail->next = nodeToAdd;
    tail = nodeToAdd;
}

Node* sortList(Node *head)
{
    // Write your code here.
//     Node *dummyNode = new Node(-1); // But we can not use this same ref for all. We need 3 different dummy nodes.
    Node *zeroHead = new Node(-1), *oneHead = new Node(-1), *twoHead = new Node(-1);
    Node *zeroTail = zeroHead, *oneTail = oneHead, *twoTail = twoHead;
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            insert_at_tail(zeroTail, curr);
        }else if(curr->data == 1){
            insert_at_tail(oneTail, curr);
        }else{
            insert_at_tail(twoTail, curr);
        }
        curr = curr->next;
    }
    // Now, merge, ignore the -1 dummy nodes.
    if(oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    // Now we need to delete the -1s.
    
    head = zeroHead->next;
//     delete nodes which are pointing to -1
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}


int main(){
    Node *node1 = new Node(0);
    Node *head = node1;

    insert_at_begin(head, 0);
    insert_at_begin(head, 1);
    insert_at_begin(head, 2);
    insert_at_begin(head, 2);
    insert_at_begin(head, 0);
    insert_at_begin(head, 1);

    printLL(head);
    Node *ans = sortList(head);
    printLL(ans);

}