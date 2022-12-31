// https://leetcode.com/problems/reverse-linked-list/description/
// https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897
#include<iostream>
using namespace std;

class ListNode{
    public:
    ListNode* next;
};

// class LinkedListNode{
//     public:
//     LinkedListNode* next;
// };


//****************************************************************

    //Following is the class structure of the LinkedListNode class:

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//*****************************************************************/


////////////////// Solution 1 : Iterative ////////////////////////////////
ListNode* reverseList(ListNode* head) {
    if(head == NULL or head->next == NULL) return head;
    ListNode* prev = NULL;
    ListNode *curr = head;
    ListNode* nextNode = NULL;

    while(curr != NULL){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    // Dry Run, at last prev will be at original Last Node. So,
    // This is our new head.
    return prev;
}
////////////////////////////////////////////////////////////////////////////

////////////////// Solution 2 : Recursive1 //////////////////////////////////

void reverseLL(ListNode* &head, ListNode *curr, ListNode *prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    reverseLL(head,curr->next,curr);
    curr->next = prev;
}

ListNode* reverseList(ListNode* head) {
    reverseLL(head,head,NULL);
    return head;
}

////////////////////////////////////////////////////////////////////////////

////////////////// Solution 3 : Recursive2 //////////////////////////////////

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head == NULL or head->next == NULL){
        return head;
    }
    LinkedListNode<int> *headSP = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return headSP;
}

////////////////////////////////////////////////////////////////////////////


int main(){

    return 0;
}