#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string S) {
    stack<int> st;

    for (char c : S) {
        if (isdigit(c)) {
            st.push(c - '0');  
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string S = "231*+9-";
    int result = evaluatePostfix(S);
    cout << "Result: " << result << endl;

    return 0;
}
