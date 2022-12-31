// https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250

#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;


Node *findMiddle(Node *head) {
    // Write your code here
    Node* sp = head;
    Node* fp = head; // Can't be NULL as length of LL >= 1.
    while(1){
        if(fp->next == NULL) return sp;
        if(fp->next->next == NULL) return sp->next;
        
        sp = sp->next;
        fp = fp->next->next;
    }
}

int main(){
    Node *node1 = new Node(80);
    Node *head = node1;

    insert_at_begin(head, 70);
    insert_at_begin(head, 60);
    insert_at_begin(head, 50);

    printLL(head);

    Node* ans = findMiddle(head);
    cout << ans->data << endl;

}
