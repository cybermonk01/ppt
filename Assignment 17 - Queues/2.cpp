#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();

    int totalSum = 0;
    int maxSum = nums[0];
    int minSum = nums[0];

    int curMax = nums[0];
    int curMin = nums[0];

    for (int i = 1; i < n; i++) {
        totalSum += nums[i];

        curMax = max(curMax + nums[i], nums[i]);
        maxSum = max(maxSum, curMax);

        curMin = min(curMin + nums[i], nums[i]);
        minSum = min(minSum, curMin);
    }

    if (maxSum < 0) {
        return maxSum;
    }

    int maxCircularSum = totalSum - minSum;

    return max(maxSum, maxCircularSum);
}

int main() {
    vector<int> nums = {1, -2, 3, -2};

    int maxSum = maxSubarraySumCircular(nums);

    cout << maxSum << endl;

    return 0;
}
