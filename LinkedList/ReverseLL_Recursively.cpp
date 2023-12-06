#include <bits/stdc++.h>
using namespace std; 

class node{
    public:
    int data;
    node* next;   

    node(int x){
        data = x;
        next = NULL;
    }
};

void insertAtTail( node* &head, int val){    
    node* n = new node(val);

    if(head==NULL) {
        head = n;
        return;
    }
    node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = n;
}

void insertAtHead( node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void display(node* head){     //only head bcoz we are not modifying the linkedlist
    
    node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

node* reverseRecursive(node* &head){

    if(head == NULL || head->next == NULL)    return head;

    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

int main() {

    node* head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    display(head);
    
    cout<<"\n";

    node* newhead = reverseRecursive(head);

    display(newhead);

    return 0;
}