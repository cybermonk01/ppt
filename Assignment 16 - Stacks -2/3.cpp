#include <iostream>
#include <stack>

using namespace std;

void deleteMiddleElement(stack<int>& st, int k) {
     if (st.empty() || k == 0) {
        return;
    }

     int temp = st.top();
    st.pop();

     deleteMiddleElement(st, k - 1);

     if (k != st.size() + 1) {
        st.push(temp);
    }
}

int main() {
    stack<int> st1;
    stack<int> st2;

    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    cout << "Original stack: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    st2.push(5);
    st2.push(6);

    cout << "Original stack: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    deleteMiddleElement(st1, st1.size() / 2 + 1);
    deleteMiddleElement(st2, st2.size() / 2 + 1);

    cout << "Modified stack: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    cout << "Modified stack: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    return 0;
}
