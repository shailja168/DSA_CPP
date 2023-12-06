#include <bits/stdc++.h>
using namespace std; 

/*Floyd's Algorithm or Hare and Tortoise Algorithm*/

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

void display(node* head){         
    node* ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
            return true;
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow);
    
    fast = head;
    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

void makeCycle(node* &head, int pos){
    node* ptr = head;
    node* startnode;

    int count = 1;
    while (ptr->next != NULL){
        
        if(count == pos)
            startnode = ptr;

        ptr = ptr->next;
        count++;
    }
    ptr->next = startnode;
}

int main() {

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);

    makeCycle(head, 2);

    if(detectCycle(head))   
        cout<<"Cycle present\n";
    else                    
        cout<<"Cycle not present\n";

    removeCycle(head);

    display(head);

    return 0;
}