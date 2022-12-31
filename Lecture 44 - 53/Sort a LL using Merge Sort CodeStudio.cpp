// https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514?leftPanelTab=0

#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;

pair<Node* ,Node*> small_large_LL(Node* x, Node* y){
    if(x->data <= y->data) return make_pair(x,y);
    else return make_pair(y,x);
}

Node* merge(Node* first, Node* second){
    // Write your code here.
    if(first == NULL) return second;
    if(second == NULL) return first;
    
    pair<Node*, Node*> llPair = small_large_LL(first, second);
    Node *headToReturn = llPair.first, *prev = llPair.first;
    second = llPair.second; // Coz second is already a parameter.
    Node* curr = prev->next;
    while( curr!= NULL && second != NULL){
        if(curr->data <= second-> data){
            prev = curr;
            curr = curr->next;
        }else{
            prev->next = second;
            second = second->next;
            prev = prev->next;
            prev->next = curr;
        }
    }
    if(second != NULL) prev->next = second;
    
    return headToReturn;
}

Node* findMiddle(Node* l){
    Node* slow = l;
    Node* fast = l->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node *head) {
    // Write your code here.
    if(head == NULL or head->next == NULL) return head;
    Node *mid = findMiddle(head);
    Node *left = head, *right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

int main(){
    Node *node1 = new Node(0);
    Node *head = node1;

    insert_at_begin(head, 0);
    insert_at_begin(head, 4);
    insert_at_begin(head, 6);
    insert_at_begin(head, 3);
    insert_at_begin(head, -7);
    insert_at_begin(head, 12);

    printLL(head);
    Node *ans = mergeSort(head);
    printLL(ans);

}
