// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0
#include "LinkedListCode.cpp"
#include<iostream>
#include<map>
using namespace std;

//////////////////////////////////////  Another Solution //////////////////////////////////

Node* sortTwoLists_sol3(Node* first, Node* second)
{
    // Write your code here.
    if(first == NULL) return second;
    Node *prev = NULL, *curr = first;
    while(curr != NULL and second != NULL){
        if(curr->data < second->data){
            prev = curr;
            curr = curr->next;
        }else{
            if(prev != NULL) {
                prev->next = second;
                second = second->next;
                prev = prev->next;
                prev->next = curr;
            }else{
                first = second;
                prev = second;
                second = second->next;
                prev->next = curr;
            }
        }
    }
    if(second != NULL){
        prev->next = second;
    }   
   return first;     
}


///////////////////////////////////////////////////////////////////////////////////////////////




/////// Solution using extra space /////////////////////////////////////////////////////////
void insert_at_end(Node* &head,Node* &tail, int val){ // O(1) insertion.
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}
Node* sortTwoLists_sol2(Node* first, Node* second)
{
    Node *head = NULL,*tail = NULL; // head will be head of our answer LL.
    while(first != NULL and second !=NULL){
        if(first->data < second->data){
            insert_at_end(head,tail,first->data);
            first = first->next;
        }else{
            insert_at_end(head,tail,second->data);
            second = second->next;
        }
    }
    // Now one LL is exhausted.
    while(first!=NULL){
        insert_at_end(head,tail,first->data);
        first = first->next;
    }
    while(second!=NULL){
        insert_at_end(head,tail,second->data);
        second = second->next;
    }
    return head;
}

/////////////////////////////////////////////////////////////////////////////





pair<Node*,Node*> small_large_LL(Node* x, Node* y){
    if(x->data <= y->data) return make_pair(x,y);
    else return make_pair(y,x);
}

Node* sortTwoLists(Node* first, Node* second)
{
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

int main(){
    Node *node1 = new Node(6);
    Node *head1 = node1;

    insert_at_begin(head1, 5);
    insert_at_begin(head1, 2);
    insert_at_begin(head1, 1);

    Node *node2 = new Node(4);
    Node *head2 = node2;

    insert_at_begin(head2, 3);
    insert_at_begin(head2, 2);
    insert_at_begin(head2, 1);

    Node *merged = sortTwoLists(head1, head2);
    printLL(merged);


}