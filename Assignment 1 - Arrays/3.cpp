#include <vector>
#include <iostream>


using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
  vector<int> nums = { 1, 3, 5, 6 };
    int target = 5;
    int result = searchInsert(nums, target);

  cout << "Index: " << result <<endl;

    return 0;
}