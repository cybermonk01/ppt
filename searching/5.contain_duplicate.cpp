#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;

    for (int num : nums) {
        if (numSet.count(num) > 0) {
            return true;  // Duplicate found
        }
        numSet.insert(num);
    }

    return false;  // No duplicates found
}

int main() {
    // Example usage
    vector<int> nums = {1, 2, 3, 1};
    bool hasDuplicate = containsDuplicate(nums);

    cout << "Contains Duplicate: " << (hasDuplicate ? "true" : "false") << endl;

    return 0;
}
