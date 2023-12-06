#include <iostream>
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

node* appendKNodes(node* &head, int k){
    node* newtail = head;
    node* newhead = head;
    node* ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    for (int i = 1; i < k; i++){
        newtail = newtail->next;
    }
    newhead = newtail->next;
    newtail->next = NULL;
    ptr->next = head;

    return newhead;
}

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
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    int k;
    cin>>k;

    display(appendKNodes(head,k));

    return 0;
}