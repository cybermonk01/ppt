#include <iostream>
#include <vector>
#include <unordered_map>

int findMaxLength(std::vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    int sum = 0;

     std::unordered_map<int, int> sumMap;
    sumMap[0] = -1; // Initialize the sum 0 at index -1

    for (int i = 0; i < n; ++i) {
        // Treat 0 as -1
        if (nums[i] == 0) {
            sum -= 1;
        } else {
            sum += 1;
        }

         if (sumMap.find(sum) != sumMap.end()) {
             maxLen = std::max(maxLen, i - sumMap[sum]);
        } else {
             sumMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    std::vector<int> nums = {0, 1};
    int result = findMaxLength(nums);
    std::cout << result << std::endl; // Output: 2

    return 0;
}
