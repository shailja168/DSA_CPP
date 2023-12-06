#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool redundant_parenthesis(string x){
    stack<int> s;
    bool ans = false;
    for (int i = 0; i < x.length(); i++){
        if(x[i] == '+' || x[i] == '-' || x[i] == '/' || x[i] == '*' || x[i] == '('){
            s.push(x[i]);
        }
        else if(x[i] == ')'){
            if(s.top() == '('){
                ans = true;
            }
            while(s.top() == '+' || s.top() == '-' || s.top() == '/' || s.top() == '*'){
                s.pop();
            }
            s.pop();
        }
    }
    return ans;
}

int main() {

    string x;
    cin >> x;

    cout << redundant_parenthesis(x);
    
    return 0;
}