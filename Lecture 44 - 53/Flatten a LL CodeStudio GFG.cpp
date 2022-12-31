// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<iostream>
using namespace std;

// Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

/*  Function which returns the  root of 
    the flattened linked list. */

Node *Merge(Node *first, Node *second){
    
    if(first == NULL) return second;
    if(second == NULL) return first;
    
    Node *temp = new Node(-1);
    Node *ans = temp;
    while(first != NULL and second != NULL){
        if(first->data <= second->data){
            temp->bottom = first;
            first = first->bottom;
            temp = temp->bottom;
        }else{
            temp->bottom = second;
            second = second->bottom;
            temp = temp->bottom;
        }
    }
    if(first != NULL){
        temp->bottom = first;
    }
    if(second != NULL){
        temp->bottom = second;  
    }
    
    return ans->bottom;
}    
    
    
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL or root->next == NULL) return root;
   
   Node *rightPart = flatten(root->next);
   Node *headToReturn = Merge(root, rightPart);
   return headToReturn;
}