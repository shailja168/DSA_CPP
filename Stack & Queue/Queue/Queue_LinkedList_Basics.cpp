#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int x){
        data = x;
        next = NULL;
    }
};

class queue{
    node *front;
    node *back;

    public:queue(){
        front = NULL;
        back = NULL;
    }

    void enqueue(int x){
        node *n = new node(x);
        if(front==NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void dequeue(){
        if(front==NULL){
            cout << "No elements in the queue\n";
            return;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }
    int peek(){
        if(front==NULL){
            cout << "No elements in the queue\n";
            return -1;
        }

        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }

};

int main() {

    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek();
    q.dequeue();
    cout << endl << q.peek();
    q.dequeue();
    cout << endl << q.peek();
    q.dequeue();
    cout << endl << q.empty();

    return 0;
}