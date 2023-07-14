#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nearestSmallerElements(vector<int>& a) {
    int n = a.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[i] <= a[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = a[s.top()];
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> a = {4, 5, 2, 10, 8};

    vector<int> nearestSmaller = nearestSmallerElements(a);

    cout << "Nearest Smaller Elements: ";
    for (int num : nearestSmaller) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
