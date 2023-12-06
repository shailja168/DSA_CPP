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
        q1.push(x);
        n++;
    }

    void pop(){
        if(q1.empty()){
            cout << "Queue is empty\n";
            exit(0);
        }
        while (q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        n--;

        //swapping q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        
    }

    int top(){
        if(q1.empty()){
            cout << "Queue is empty\n";
            return -1 ;
        }
        while (q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q1.pop(); //remove the residual top value
        q2.push(ans);

        //swapping q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
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

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    cout << st.empty() << endl;

    return 0;
}