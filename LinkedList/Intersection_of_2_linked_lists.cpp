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

int length(node* head){
    node* ptr = head;
    int count = 0;
    while(ptr != NULL){
        ptr= ptr->next;
        count++;
    }
    return count;
}

int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int diff = abs(l1 - l2);

    node* ptr1 = head1;
    node* ptr2 = head2;

    if(l1>l2)
        while(diff){
            ptr1 = ptr1->next;
            diff--;
        }
    else
        while(diff){
            ptr2 = ptr2->next;
            diff--;
        }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1== ptr2)
            return ptr1->data;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
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
    node* head1 = NULL;
    node* head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    insertAtTail(head1, 7);

    insertAtTail(head2, 10);

    node* ptr = head1;
    for (int i = 1; i < 5; i++)
        ptr = ptr->next;
    
    head2 -> next = ptr;

    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;

    cout<<"intersection at: "<<intersection(head1, head2);

    return 0;
}