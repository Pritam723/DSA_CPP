// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331
#include "LinkedListCode.cpp"
#include<iostream>
#include<unordered_map>
using namespace std;

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_map<int, bool> nodeMap;
    Node *prev = NULL, *curr = head, *nodeToDelete = NULL;
    while(curr != NULL){
        if(nodeMap.count(curr->data) == 0){
            nodeMap[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }else{
            nodeToDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            nodeToDelete->next = NULL;
            delete nodeToDelete;
        }
    }
    return head;
}

int main(){
    Node *node1 = new Node(2);
    Node *head = node1;

    insert_at_begin(head, 1);
    insert_at_begin(head, 1);
    insert_at_begin(head, 3);
    insert_at_begin(head, 4);
    insert_at_begin(head, 4);

    printLL(head);

    head = removeDuplicates(head);
    
    printLL(head);

}