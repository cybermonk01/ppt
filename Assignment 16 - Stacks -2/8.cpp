#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maxAbsoluteDifference(const vector<int>& arr) {
    int n = arr.size();
    vector<int> LS(n, 0);  
    vector<int> RS(n, 0); 

    stack<int> st;  

     for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        LS[i] = st.empty() ? 0 : arr[st.top()];
        st.push(i);
    }

    while (!st.empty()) {
        st.pop();
    }

     for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        RS[i] = st.empty() ? 0 : arr[st.top()];
        st.push(i);
    }

    int maxDiff = 0;

    for (int i = 0; i < n; i++) {
        maxDiff = max(maxDiff, abs(LS[i] - RS[i]));
    }

    return maxDiff;
}

int main() {
    vector<int> arr = {2, 1, 8};

    int maxDiff = maxAbsoluteDifference(arr);

    cout << "Maximum absolute difference: " << maxDiff << endl;

    return 0;
}
