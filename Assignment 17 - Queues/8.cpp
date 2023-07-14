#include <iostream>
#include <deque>

using namespace std;

class DataStream {
public:
    DataStream(int value, int k) : value(value), k(k) {

    }

    bool consec(int num) {
        nums.push_back(num);
        if (nums.size() > k) {
            nums.pop_front();
        }
        return nums.size() == k && equal(nums.begin(), nums.end(), value);
    }

private:
    bool equal(const deque<int>& nums, int value) {
        for (int num : nums) {
            if (num != value) {
                return false;
            }
        }
        return true;
    }

    deque<int> nums;
    int value;
    int k;
};

int main() {
    DataStream stream(5, 3);
    cout << stream.consec(2) << endl;
    cout << stream.consec(5) << endl;
    cout << stream.consec(5) << endl;
    cout << stream.consec(5) << endl;
    cout << stream.consec(3) << endl;
    return 0;
}
