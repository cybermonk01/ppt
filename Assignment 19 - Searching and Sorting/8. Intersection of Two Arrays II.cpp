#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;

    for (int num : nums1) {
        freq1[num]++;
    }

    vector<int> result;
    for (int num : nums2) {
        if (freq1[num] > 0) {
            freq1[num]--;
            result.push_back(num);
        }
    }

    return result;
}

int main() {
 
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> intersected = intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : intersected) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
