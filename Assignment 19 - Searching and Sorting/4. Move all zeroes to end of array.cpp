#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[i - zeroCount] = nums[i];
        } else {
            zeroCount++;
        }
    }

    for (int i = n - zeroCount; i < n; i++) {
        nums[i] = 0;
    }
}

int main() {
    
    vector<int> nums = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};

    moveZeroes(nums);

    cout << "Modified Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
