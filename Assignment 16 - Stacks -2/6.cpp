#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseK(queue<int>& q, int k) {
    stack<int> st;
    int n = q.size();

     for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

     while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

     for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    cout << "Queue before reversing: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

     reverseK(q, k);

    cout << "Queue after reversing: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
