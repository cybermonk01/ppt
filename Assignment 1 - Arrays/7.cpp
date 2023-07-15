#include <vector>
using  namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        if (nums[right] != 0) {
           std::swap(nums[left], nums[right]);
            left++;
        }
    }
    
    while (left < n) {
        nums[left] = 0;
        left++;
    }
}
