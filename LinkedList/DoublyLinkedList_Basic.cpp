#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* ptr = head;
    while( ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = n;
    n->prev = ptr;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head->prev = n;

    if(head != NULL)
        head = n;
}

void deletion(node* &head, int pos){   

    if(pos == 1){
        node* todelete = head;
        head = head->next;
        head->prev = NULL;
        delete todelete;
        return;
    } 

    node* ptr = head;
    int count = 1;
    while(ptr != NULL && count != pos){
        ptr = ptr->next;
        count++;
    }
    ptr->prev->next = ptr->next;

    if(ptr->next != NULL)         //if pos = last element
        ptr->next->prev = ptr->prev;  

    delete ptr;
}

void display(node* head){
    node* ptr = head;
    while (ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    display(head);

    deletion(head, 1);

    cout<<endl;
    display(head);

    deletion(head, 4);
    
    cout<<endl;
    display(head);

    return 0;
}