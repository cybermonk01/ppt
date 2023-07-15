#include <vector>
#include <iostream>


using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}
int main() {
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    int m = 3;
vector<int> nums2 = { 2, 5, 6 };
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) {
       cout << num << " ";
    }

    return 0;
}

