#include <iostream>
using namespace std; 

class node{
    public:
    int data;
    node* next;   //it is a pointer pointing to the next node

    node(int x){
        data = x;
        next = NULL;
    }
};

void insertAtTail( node* &head, int val){    //using &head bcoz we are modifying the linkedlist
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

bool search(node* head, int key){
   
    node* ptr = head;
    while (ptr != NULL)
    {
        if(ptr->data == key){
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

void deletion(node* &head, int val){
    node* ptr = head;

    if(head == NULL)
        return;

    if(head->next == NULL){
        head = NULL;
        return;
    }

    if(head->data == val){   //deletion at head
        head = head->next;
        return;
    }

    while (ptr->next->data != val)
    {
        ptr = ptr->next;  //stores the (n-1)th node
    }
    
    node* todelete = ptr->next;    
    ptr->next = ptr->next->next;
            
    delete todelete;    //delete node to avoid memory leak
}

int main() {

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);

    insertAtHead(head,4);
    insertAtHead(head,5);
    display(head);

    if(search(head, 14)) 
        cout<<"\nelement found\n";
    else
        cout<<"\nelement not found\n";

    deletion(head, 2);
    display(head);

    return 0;
}