#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }

    int n = nums.size();

    int minValue = *min_element(nums.begin(), nums.end());
    int maxValue = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (maxValue - minValue) / (n - 1));
    int bucketCount = (maxValue - minValue) / bucketSize + 1;

    vector<pair<int, int>> buckets(bucketCount, {-1, -1});

    for (int num : nums) {
        int bucketIndex = (num - minValue) / bucketSize;
        if (buckets[bucketIndex].first == -1) {
            buckets[bucketIndex].first = num;
            buckets[bucketIndex].second = num;
        } else {
            buckets[bucketIndex].first = min(buckets[bucketIndex].first, num);
            buckets[bucketIndex].second = max(buckets[bucketIndex].second, num);
        }
    }

    int maxGap = 0;
    int prevMax = minValue;
    for (const auto& bucket : buckets) {
        if (bucket.first != -1) {
            maxGap = max(maxGap, bucket.first - prevMax);
            prevMax = bucket.second;
        }
    }

    return maxGap;
}

int main() {
    vector<int> nums = {3, 6, 9, 1};
    int maxGap = maximumGap(nums);

    cout << "Maximum Gap: " << maxGap << endl;

    return 0;
}
