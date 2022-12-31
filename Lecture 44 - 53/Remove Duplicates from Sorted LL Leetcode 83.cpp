// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=1
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head == NULL) return head;
    Node *temp = head->next, *prev = head, *nodeToDelete = NULL;
    while(temp != NULL){
        if(temp->data == prev->data){
            nodeToDelete = temp;
            temp = temp->next;
            prev->next = temp;
            delete nodeToDelete;
        }else{
            prev = prev->next;
            // Or write,
            // prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

Node* deleteDuplicates(Node* head) {
    Node *curr = head, *nodeToDelete = NULL;
    while(curr != NULL and curr->next != NULL){
        if(curr->data == curr->next->data){
            nodeToDelete = curr->next;
            curr->next = curr->next->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }else{
            curr = curr->next;
        }
    }
    return head;
}

int main(){
    Node *node1 = new Node(2);
    Node *head = node1;

    insert_at_begin(head, 1);
    insert_at_begin(head, 1);

    printLL(head); // 1-->1-->2

    head = uniqueSortedList(head);
    
    printLL(head);

}