#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2;
    
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
 
    return expectedSum - actualSum;
}

int main() {
    std::vector<int> nums = {3, 0, 1};
    int missingNumber = missingNumber(nums);

    std::cout << "The missing number is: " << missingNumber << std::endl;
    return 0;
}
