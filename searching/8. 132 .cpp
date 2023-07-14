#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int s3 = INT_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] < s3) {
            return true;
        } else {
            while (!st.empty() && nums[i] > st.top()) {
                s3 = st.top();
                st.pop();
            }
        }
        st.push(nums[i]);
    }

    return false;
}

int main() {
    // Example usage
    vector<int> nums = {3, 1, 4, 2};
    bool has132pattern = find132pattern(nums);

    cout << "Has 132 Pattern: " << (has132pattern ? "true" : "false") << endl;

    return 0;
}
