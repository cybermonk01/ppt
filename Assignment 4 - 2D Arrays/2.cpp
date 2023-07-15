#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::vector<int>> findDistinctElements(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<std::vector<int>> answer(2);
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            answer[0].push_back(num);
        }
    }

    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            answer[1].push_back(num);
        }
    }

    return answer;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {2, 4, 6};

    std::vector<std::vector<int>> answer = findDistinctElements(nums1, nums2);

    std::cout << "Output: [[";
    for (int i = 0; i < answer[0].size(); ++i) {
        std::cout << answer[0][i];
        if (i < answer[0].size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "], [";
    for (int i = 0; i < answer[1].size(); ++i) {
        std::cout << answer[1][i];
        if (i < answer[1].size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]]" << std::endl;

    return 0;
}
