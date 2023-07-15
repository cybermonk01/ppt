#include <iostream>
#include <vector>

int findDuplicate(const std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

     do {
        slow = nums[slow];           
        fast = nums[nums[fast]];    
    } while (slow != fast);

     slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

     return slow;
}

int main() {
    std::vector<int> nums = {1, 3, 4, 2, 2};
    int repeatedNumber = findDuplicate(nums);

    std::cout << "The repeated number is: " << repeatedNumber << std::endl;
    return 0;
}
