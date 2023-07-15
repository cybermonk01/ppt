#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());
    
    std::vector<int> result;
    for (int num : set1) {
        if (set2.find(num) != set2.end()) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> intersectionResult = intersection(nums1, nums2);

    std::cout << "Intersection: ";
    for (int num : intersectionResult) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
