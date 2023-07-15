#include <iostream>
#include <vector>

std::vector<int> shuffleArray(const std::vector<int>& nums, int n) {
    std::vector<int> result(2 * n);
    int index = 0;

    for (int i = 0; i < n; ++i) {
        result[index++] = nums[i];
        result[index++] = nums[n + i];
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    std::vector<int> result = shuffleArray(nums, n);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl; // Output: [2, 3, 5, 4, 1, 7]

    return 0;
}
