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

void EvenAfterOdd(node* &head){
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;
    while (odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;   //pointing the last of odd nodes to the starting of even nodes
}

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

void display(node* head){     
    node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

int main() {

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);

    EvenAfterOdd(head);
    display(head);


    return 0;
}