#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std; 

//Time Complexity = O(n) where n = lenght of the string or expression

int solve(int a, int b, char ch){
    switch (ch){
    case '+': return a + b; break;
    case '-': return a - b; break;
    case '*': return a * b; break;
    case '/': return a / b; break;
    case '^': return pow(a,b); break;
    default:  return 0; break;
    }
}

int main() {

    stack<int> st;
    string exp;
    getline(cin, exp);

    for (int i = 0;  i < exp.length() ; i++){    //string is traversed from front 
        if (exp[i] >= '0' && exp[i] <= '9'){
            st.push(exp[i] - '0');
        }
        else if((exp[i] == '+') || (exp[i] == '-') || (exp[i] == '*') || (exp[i] == '/') || (exp[i] == '^')){
            int opd2 = st.top();    //here top most element goes to operand2
            st.pop();
            int opd1 = st.top();
            st.pop();

            int sol = solve(opd1, opd2, exp[i]);
            st.push(sol);
        }
        else{
            cout << "INCORRECT FORMAT\n";
            break;
        }
    }

    cout << st.top();

    return 0;
}