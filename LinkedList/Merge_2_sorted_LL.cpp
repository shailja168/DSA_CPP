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

// Time Complexity: O(n+m)

node* mergeiterative(node* &head1, node* &head2){

    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummy = new node(-1);
    node* ptr3 = dummy;

    while (ptr1!= NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3= ptr3->next;
    }

    while(ptr1 != NULL){
        ptr3->next = ptr1;
        ptr1= ptr1->next;
        ptr3 = ptr3->next;
    }

    while(ptr2 != NULL){
        ptr3->next = ptr2;
        ptr2= ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummy->next;
}

node* mergerecursive(node* &head1, node* &head2){

    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;

    node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergerecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergerecursive(head1, head2->next);
    }
    return result;
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
    insertAtTail(head1, 3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);

    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 7);
    insertAtTail(head2, 8);

    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;

    display(mergerecursive(head1, head2));

    return 0;
}