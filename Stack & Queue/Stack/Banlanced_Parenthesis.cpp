#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool banlancedParenthesis(string s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++){
        if ((s[i] == '{') || (s[i] == '[') || (s[i] == '(')){
            st.push(s[i]);
        }
        else if (s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
        }
        else if (!st.empty() && s[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }
        }
        else if (!st.empty() && s[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {

    string exp;
    cin >> exp;

    if(banlancedParenthesis(exp)){
        cout << "Balanced Parenthesis\n";
    }
    else{
        cout << "Parenthesis are not Balanced\n";
    }

    return 0;
}