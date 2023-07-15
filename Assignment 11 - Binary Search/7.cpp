#include <iostream>
#include <vector>

std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    std::vector<int> result(2, -1);
    int left = 0, right = nums.size() - 1;
 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            result[0] = mid;
            right = mid - 1;  
        }
    }
 
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            result[1] = mid;
            left = mid + 1;  
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    std::vector<int> result = searchRange(nums, target);

    std::cout << "Output: [" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
