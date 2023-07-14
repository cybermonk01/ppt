#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool checkQueueOrder(queue<int>& q) {
    stack<int> st;
    queue<int> tempQ;

    int expected = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            tempQ.push(front);
            expected++;
        } else {
            while (!st.empty() && st.top() == expected) {
                tempQ.push(st.top());
                st.pop();
                expected++;
            }

            st.push(front);
        }
    }

    while (!st.empty() && st.top() == expected) {
        tempQ.push(st.top());
        st.pop();
        expected++;
    }

    while (!tempQ.empty()) {
        q.push(tempQ.front());
        tempQ.pop();
    }

    return q.empty();
}

int main() {
    queue<int> q1;
    queue<int> q2;

    q1.push(5);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    cout << "Queue: ";
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    q2.push(5);
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(6);

    cout << "Queue: ";
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    bool result1 = checkQueueOrder(q1);
    bool result2 = checkQueueOrder(q2);

    cout << "Can be arranged in increasing order: " << (result1 ? "Yes" : "No") << endl;
    cout << "Can be arranged in increasing order: " << (result2 ? "Yes" : "No") << endl;

    return 0;
}
