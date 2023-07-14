#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> result;
    for (int num : set1) {
        if (set2.count(num) > 0) {
            result.push_back(num);
        }
    }

    return result;
}

int main() {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> intersect = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : intersect) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
