#include <iostream>
#define n 20
using namespace std;

class queue{
    public:
    int* que;
    int front;
    int back;

    queue(){
        que = new int[n];
        front = -1;
        back = -1;
    } 
    
    void enqueue(int x){
        if(back == n-1){
            cout << "Queue Overflow\n";
            return;
        }
        que[++back] = x;

        if(front==-1){
            front++;
        }
    }
    void dequeue(){
        if(front == -1 || front>back){
            cout << "Queue is Empty\n";
            return;
        }
        front++;
    }
    int peek(){
        if(front == -1 || front>back){
            cout << "Queue is Empty\n";
            return -1;
        }
        return que[front]; 
    }
    bool empty(){
        return (front == -1 || front>back);
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