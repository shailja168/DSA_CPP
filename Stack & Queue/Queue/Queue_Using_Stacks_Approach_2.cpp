#include <iostream>
#include <stack>
using namespace std;

class que{
    stack<int> st;

    public:
    void enqueue(int x){
        st.push(x);
    }
    int dequeue(){
        if(st.empty()){
            cout << "Queue is empty\n";
            exit(0);
        }
    
        int x = st.top();
        st.pop();
        if(st.empty()){
            return x;
        }
        int item = dequeue();
        st.push(x); //push the previouly removed elements back
        return item;
    }

    bool empty(){
        return (st.empty());
    }
};

int main() {

    que q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.dequeue();
    cout << q.empty() << endl;

    return 0;
}