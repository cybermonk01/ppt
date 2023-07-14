#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& st) {
    stack<int> tempSt;

    while (!st.empty()) {
        int temp = st.top();
        st.pop();

        while (!tempSt.empty() && temp < tempSt.top()) {
            st.push(tempSt.top());
            tempSt.pop();
        }

        tempSt.push(temp);
    }

     while (!tempSt.empty()) {
        st.push(tempSt.top());
        tempSt.pop();
    }
}

int main() {
    stack<int> st1;
    stack<int> st2;

    st1.push(34);
    st1.push(3);
    st1.push(31);
    st1.push(98);
    st1.push(92);
    st1.push(23);

    cout << "Original stack: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    st2.push(3);
    st2.push(5);
    st2.push(1);
    st2.push(4);
    st2.push(2);
    st2.push(8);

    cout << "Original stack: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    sortStack(st1);
    sortStack(st2);

    cout << "Sorted stack: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    cout << "Sorted stack: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    return 0;
}
