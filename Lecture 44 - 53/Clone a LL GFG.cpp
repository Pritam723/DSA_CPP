// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

#include<iostream>
#include<map>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *arb;

    Node(int x){
        data = x;
        next = NULL;
        arb = NULL;
    }
};


// Solution using Map //////////////////////////////////////////////////////////////////
void insert_at_tail(struct Node * &head, struct Node * &tail, int data){
    struct Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


Node *copyList(Node *head)
{
    //Write your code here
    struct Node *cloneHead = NULL;
    struct Node *cloneTail = NULL;
    struct Node *temp = head;
    map<struct Node*, struct Node*> nodeMap;
    
    // Copying the next pointers first. And making the MAP.
    while(temp != NULL){
        
        insert_at_tail(cloneHead, cloneTail, temp->data);
        nodeMap[temp] = cloneTail; // Coz cloneTail is moving with the traversal of Original LL.
        temp = temp->next;
    }
    
    // Now copying the 'arb' pointers.
    temp = head;
    struct Node *cloneTemp = cloneHead;
    while(temp != NULL){
        cloneTemp->arb = (temp->arb) ? nodeMap[temp->arb] : NULL; // Coz temp->arb can be NULL.
        cloneTemp = cloneTemp->next;
        temp = temp->next;
    }
    return cloneHead;
}





// Solution using no extra space //////////////////////////////////////////////////////////////////

void insert_after(Node *temp){
    Node *nodeToInsert = new Node(temp->data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

class Solution
{
    public:
    Node *copyList(Node *head){
        //Write your code here
        struct Node *cloneHead = NULL, *cloneTail = NULL, *temp = head, *cloneTemp = NULL;
        while(temp != NULL){
            insert_after(temp);
            temp = temp->next->next;
        }
        
        cloneHead = head->next;
        
        temp = head;
        cloneTemp = cloneHead;
        
        while(temp != NULL){
            temp->next->arb = (temp->arb != NULL) ? temp->arb->next : NULL;
            temp = temp->next->next;
        }
        
        temp = head;
        cloneTemp = cloneHead;
        
        
        while(temp != NULL){
            temp->next = temp->next->next;
            
            if(cloneTemp->next)
                cloneTemp->next = temp->next->next;
            else
                cloneTemp->next = NULL;
                
            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }
        
        return cloneHead;
    }

};