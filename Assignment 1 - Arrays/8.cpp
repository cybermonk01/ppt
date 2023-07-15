#include <vector>
#include <algorithm>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(2, -1);

    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        if (nums[num - 1] > 0) {
            nums[num - 1] *= -1;
        } else {
            result[0] = num;
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result[1] = i + 1;
            break;
        }
    }

    return result;
}
