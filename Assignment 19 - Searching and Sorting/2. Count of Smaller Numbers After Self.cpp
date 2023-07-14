#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    vector<int> counts(nums.size());
    multimap<int, int> sorted;

    for (int i = nums.size() - 1; i >= 0; i--) {
        counts[i] = distance(sorted.begin(), sorted.lower_bound(nums[i]));
        sorted.insert({nums[i], i});
    }

    return counts;
}

int main() {

    vector<int> nums = {5, 2, 6, 1};
    vector<int> counts = countSmaller(nums);

    cout << "Counts: ";
    for (int count : counts) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
