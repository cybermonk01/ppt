#include <vector>
#include <iostream>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
int main() {
  vector<int> nums = { 3, 2, 2, 3 };
    int val = 3;
    int count = removeElement(nums, val);

   cout << "Count: " << count << ", nums = ";
    for (int i = 0; i < count; i++) {
      cout << nums[i] << " ";
    }

    return 0;
}
