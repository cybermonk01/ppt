#include <iostream>
#include <vector>

int findMin(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
             left = mid + 1;
        } else {
             right = mid;
        }
    }

  
    return nums[left];
}

int main() {
    std::vector<int> nums = {3, 4, 5, 1, 2};
    int minElement = findMin(nums);

    std::cout << "The minimum element is: " << minElement << std::endl;
    return 0;
}
