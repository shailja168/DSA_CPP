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

void insertAtHead(node* &head, int val){
    node *n = new node(val);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    node *ptr = head;
    while( ptr->next != head){
        ptr = ptr->next;
    }
    n->next = head;
    ptr->next = n;
    head = n;
}

void insertAtTail(node* &head, int val){
    node *n = new node(val);
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    node *ptr = head;
    while( ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = head;
}

void deletion(node* &head, int pos){
    if(pos == 1){       //deletion at head position
        node *ptr = head;
        while( ptr->next != head){
            ptr = ptr->next;
        }
        node *todelete = head;
        ptr->next = head->next;
        head = head->next;
        delete todelete;
        return;
    }
    node *ptr = head;
    int temp = 1;
    while(temp < pos-1){
        ptr = ptr->next;
        temp++;
    }
    node* todelete = ptr->next;
    ptr->next = ptr->next->next;
    delete todelete;
}

void display(node* head){
    node* ptr = head;
    do{
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    insertAtHead(head1, 50);
    insertAtTail(head1, 1);
    insertAtTail(head1, 3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtHead(head1, 45);

    display(head1);

    deletion(head1, 1);

    display(head1);

    return 0;
}