#include <iostream>
#include <vector>
#include <algorithm>

int minProductSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    int n = nums1.size();
    
     std::sort(nums1.begin(), nums1.end());
    
     std::sort(nums2.rbegin(), nums2.rend());
    
    int productSum = 0;
    for (int i = 0; i < n; ++i) {
         productSum += nums1[i] * nums2[i];
    }
    
    return productSum;
}

int main() {
    std::vector<int> nums1 = {5, 3, 4, 2};
    std::vector<int> nums2 = {4, 2, 2, 5};
    
    int result = minProductSum(nums1, nums2);
    std::cout << result << std::endl; // Output: 40
    
    return 0;
}
