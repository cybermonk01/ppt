#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0;  
    }

    int water = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) {
                break;
            }
            int distance = i - st.top() - 1;
            int boundedHeight = min(height[i], height[st.top()]) - height[top];
            water += distance * boundedHeight;
        }
        st.push(i);
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trap(height);
    cout << "Trapped Water: " << trappedWater << endl;

    return 0;
}
