#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 25};

    vector<int> nextGreater = nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int num : nextGreater) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
