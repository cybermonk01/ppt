#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1, q2;
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.top() << endl;
    cout << stack.pop() << endl;
    cout << stack.empty() << endl;
    return 0;
}