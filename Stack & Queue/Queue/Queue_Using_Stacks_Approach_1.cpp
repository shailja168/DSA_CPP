#include <iostream>
#include <stack>
using namespace std;

//Here dequeue is made costly 
//In the same method of 2 stacks, we can also make enqueue costly

class queue{
    stack<int> st1;
    stack<int> st2;

    public:
    void enqueue(int x){
        st1.push(x);
    }
    void dequeue(){
        if(st1.empty() && st2.empty()){
            cout << "queue is empty\n";
            return;
        }
        if(!st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        st2.pop();
    }
    int peek(){
        if(st1.empty() && st2.empty()){
            cout << "queue is empty\n";
            return -1;
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    bool empty(){
        return (st1.empty() && st2.empty());
    }
};

int main() {

    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.empty() << endl;

    return 0;
}