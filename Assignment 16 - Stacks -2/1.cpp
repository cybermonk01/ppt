#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> findNextGreaterFrequency(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    unordered_map<int, int> frequency;

 
    for (int num : arr) {
        frequency[num]++;
    }

    stack<int> st;
    st.push(0);  

    for (int i = 1; i < n; i++) {
        while (!st.empty() && frequency[arr[i]] > frequency[arr[st.top()]]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 4, 2, 1};
    vector<int> result = findNextGreaterFrequency(arr);

    cout << "Result: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
