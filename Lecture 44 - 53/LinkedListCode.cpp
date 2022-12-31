#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_begin(Node * &head, int data){
    Node *nodeToInsert = new Node(data);
    // if(head == NULL){
    //     head = nodeToInsert;
    //     return;
    // } // No need though.
    nodeToInsert->next = head;
    head = nodeToInsert;

}

void printLL(Node * &head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node * &head){
    Node *temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}