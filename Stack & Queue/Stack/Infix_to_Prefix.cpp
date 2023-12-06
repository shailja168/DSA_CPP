#include <iostream>
#include <stack>
#include <algorithm>
using namespace std; 

int prec(char op){
    if(op == '^'){
        return 3;
    }
    else if((op == '*') || (op == '/')){
        return 2;
    }
    else if((op == '+') || (op == '-')){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPrefix(string exp){
    stack<char> st;
    string result;
    for (int i = 0;  i < exp.length() ; i++){    //string is traversed from front 
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
            result += exp[i];
        }
        else if(exp[i] == '('){
            st.push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else if((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '^')){
            while(!st.empty() && (prec(st.top()) > prec(exp[i]))){
                result += exp[i];
                st.pop();
            }
            st.push(exp[i]);
        }
        else{
            return "INCORRECT FORMAT\n";
        }
    }

    while (!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {

    string exp;
    cin >> exp;

    //for prefix we use the same logic as posrfix
    //ONLY CHANGE: Reverse string and make '(' to ')' and ')' to '('
    reverse(exp.begin(), exp.end());    
    for (int i = 0; i < exp.length(); i++){
        if(exp[i] == '('){
            exp[i] = ')';
            continue;
        }
        else if(exp[i] == ')'){
            exp[i] = '(';
        }
    }
    
    string result = infixToPrefix(exp);

    //Reverse the result string to get prefix expression
    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}