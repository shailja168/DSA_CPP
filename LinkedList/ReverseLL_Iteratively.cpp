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

node* reverse(node* &head){

    if(head == NULL || head->next == NULL)    return 0;

    node* prevptr = NULL;
    node* currptr = head;
    node* nxtptr;

    while(currptr != NULL){
        nxtptr = currptr->next;   //important to store the next pointer

        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nxtptr;

    }

    return prevptr;
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

    node* newhead = reverse(head);

    display(newhead);

    return 0;
}