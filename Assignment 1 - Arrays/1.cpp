#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
 vector<int> result;
    int left = 0;
    int right = nums.size() - 1;

    sort(nums.begin(), nums.end());

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            result.push_back(left);
            result.push_back(right);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}
int main() {
vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

  vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
       cout << "Indices: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
      cout << "No solution found." << std::endl;
    }

    return 0;
}
