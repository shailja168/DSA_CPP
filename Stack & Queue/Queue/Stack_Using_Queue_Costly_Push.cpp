#include <iostream>
#include <queue>
using namespace std;

class Stack{
    int n;  //stack size
    queue<int> q1, q2;

    public:
    Stack(){
        n = 0;
    }
    void push(int x){
        q2.push(x);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        //swapping q1 and q2

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        if(q1.empty()){
            cout << "Queue is empty\n";
            exit(0);
        }
        q1.pop();
        n--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return n;
    }

    bool empty(){
        return (q1.empty());
    }
};

int main() {

    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << st.size() << endl;

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.size() << endl;

    cout << st.empty() << endl;

    return 0;
}