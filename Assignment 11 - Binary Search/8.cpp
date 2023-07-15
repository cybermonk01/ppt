#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersect(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_map<int, int> count1;
    for (int num : nums1) {
        count1[num]++;
    }

    std::vector<int> result;
    for (int num : nums2) {
        if (count1[num] > 0) {
            result.push_back(num);
            count1[num]--;
        }
    }

    return result;
}

int main() {
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};
    std::vector<int> intersectionResult = intersect(nums1, nums2);

    std::cout << "Intersection: ";
    for (int num : intersectionResult) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
