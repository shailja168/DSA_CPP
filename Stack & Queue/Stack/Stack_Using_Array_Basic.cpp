#include <iostream>
using namespace std; 
# define n 100

class stack{
    int *arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top==(n-1)){
            cout << "stack overflow\n";
            return;
        }
        arr[++top] = x;
    }
    
    void pop(){
        if(top == -1){
            cout << "empty stack\n";
            return;
        }
        top--;
    }

    int Top(){
        if(top == -1){
            cout << "empty stack\n";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};

int main() {

    stack st;
    st.push(20);
    st.push(90);
    st.push(88);
    cout << st.Top();
    st.pop();
    cout << endl << st.Top();
    st.pop();
    st.pop();
    cout << endl << st.empty();

    return 0;
}