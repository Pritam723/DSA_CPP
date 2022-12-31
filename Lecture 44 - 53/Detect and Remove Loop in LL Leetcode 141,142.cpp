// https://leetcode.com/problems/linked-list-cycle/description/
// https://leetcode.com/problems/linked-list-cycle-ii/description/
// https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049
// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include "LinkedListCode.cpp"
#include<iostream>
using namespace std;

bool hasCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

Node *detectCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while(true){
        if(fast == NULL or fast->next == NULL) return NULL;
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    
        Node *slow = head;
        Node *fast = head;
        while(true){
            if(fast == NULL or fast->next == NULL) return head;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        Node* startOfLoop = slow;
    while(slow->next != startOfLoop){
        slow = slow->next;
    }
    slow->next = NULL;
    return head;
}

int main(){
    Node *node1 = new Node(-4);
    Node *head = node1;

    insert_at_begin(head, 0);
    insert_at_begin(head, 2);
    insert_at_begin(head, 3);

    printLL(head); // (3)-->(2)-->(0)-->(-4)

    // So, head->next is adress is node(2). Let's make (-4) point to 2 to create cycle.

    node1->next = head->next;

    // Now printLL(head) will cause infinite loop.

    cout << hasCycle(head) << endl;

    cout << detectCycle(head)->data << endl; // Will print data of the node from where the loop is getting started

}