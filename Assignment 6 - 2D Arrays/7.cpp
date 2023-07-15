#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findOriginalArray(std::vector<int>& changed) {
    int n = changed.size();
    std::sort(changed.begin(), changed.end()); // Step 1
    
    std::vector<int> original;
    for (int i = 0; i < n; ++i) {
        int num = changed[i];
        if (!original.empty() && original.back() == num / 2) {
            original.pop_back(); // Step 3
        } else {
            return {}; // Step 3
        }
        original.push_back(num); // Step 2
    }
    
    return original; // Step 4
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};
    std::vector<int> original = findOriginalArray(changed);
    
    if (original.empty()) {
        std::cout << "No valid original array." << std::endl;
    } else {
        std::cout << "Original array: ";
        for (int num : original) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
