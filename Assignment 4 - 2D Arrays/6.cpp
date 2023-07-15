#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n);

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }

        index--;
    }

    return result;
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    std::vector<int> result = sortedSquares(nums);

    std::cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
