// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
// https://leetcode.com/problems/add-two-numbers/

#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;

// void insert_at_begin(struct Node* &head, int data){   // Already defined in LinkedListCode.cpp.
//     Node *nodeToAdd = new Node(data);
//     // if(head == NULL){
//     //     head = nodeToAdd;
//     //     return;
//     // }
//     nodeToAdd -> next = head;
//     head = nodeToAdd;
//     // This will also handle the NULL head case.
    
// }

void reverseLL(struct Node* &head){
    Node *prev = NULL, *curr = head, *forward = NULL;
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

////////////////////////////// Solution 1 //////////////////////////////////////////////////////////////

Node* addTwoNumbers(Node* first, Node* second) {
    // code here
    struct Node *ans = NULL;
    // reverseLL(first);
    // reverseLL(second);
    // Input : 1-9-0 and 2-5
    // Reverse is : 0-9-1 and 5-2
    int sum = 0, digit = 0, carry = 0;
    
    while(first != NULL or second != NULL or carry != 0){
        sum = (first ? first->data : 0) + (second ? second->data : 0) + carry; // If sum is 18, then carry is 1, digit is 8.
        digit = sum%10;
        carry = sum/10;
        // Add the digit to the ans. (Insert at begin will ensure that we don't need to reverse one more time)
        insert_at_begin(ans,digit);
        first = (first ? first->next : NULL);
        second = (second ? second->next : NULL);
    }
    reverseLL(ans);
    return ans;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////// Solution 2 ///////////////////////////////////////////////////////////

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    struct Node *ans = NULL;
    reverseLL(first);
    reverseLL(second);
    // Input : 1-9-0 and 2-5
    // Reverse is : 0-9-1 and 5-2
    int sum = 0, digit = 0, carry = 0;
    
    while(first != NULL or second != NULL){
        sum = (first ? first->data : 0) + (second ? second->data : 0) + carry; // If sum is 18, then carry is 1, digit is 8.
        digit = sum%10;
        carry = sum/10;
        // Add the digit to the ans. (Insert at begin will ensure that we don't need to reverse one more time)
        insert_at_begin(ans,digit);
        first = (first ? first->next : NULL);
        second = (second ? second->next : NULL);
    }
    // But we have forgot to do one part. In worst case there may be carry = 1 left.
    if(carry != 0){
        insert_at_begin(ans,carry);
    }
    return ans;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    printLL(head1);
    printLL(head2);

    Node *addedList = addTwoLists(head1, head2);
    printLL(addedList);


}