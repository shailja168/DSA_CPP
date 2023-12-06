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

node* reverseKnodes(node* &head,int k){

    if(head == NULL || head->next == NULL)    return head;

    node* prevptr = NULL;
    node* currptr = head;
    node* nxtptr;

    int count = 0;

    while (currptr != NULL && count < k){
        nxtptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nxtptr;
        count++;
    }
    
    if(nxtptr != NULL){
        head->next = reverseKnodes(nxtptr, k);
    }

    return prevptr;
}

int main() {

    node* head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtHead(head,2);
    insertAtHead(head,1);
    display(head);

    cout<<"\nEnter value of k: ";
    int k;
    cin>>k;

    node* newhead = reverseKnodes(head,k);

    display(newhead);

    return 0;
}