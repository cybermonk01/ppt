#include <iostream>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int sum = 0;

    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    std::vector<int> nums = {1, 4, 3, 2};
    int result = arrayPairSum(nums);

    std::cout << "Output: " << result << std::endl; // Output: 4

    return 0;
}
