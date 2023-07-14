#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string s) {
    stack<char> st;
    string result = "";

     for (char c : s) {
        st.push(c);
    }

     while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string S = "GeeksforGeeks";
    string reversed = reverseString(S);
    cout << "Reversed String: " << reversed << endl;

    return 0;
}
