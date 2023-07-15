#include <iostream>
#include <vector>

int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
    int minX = m;
    int minY = n;

    for (const auto& op : ops) {
        minX = std::min(minX, op[0]);
        minY = std::min(minY, op[1]);
    }

    return minX * minY;
}

int main() {
    int m = 3;
    int n = 3;
    std::vector<std::vector<int>> ops = {{2, 2}, {3, 3}};

    int result = maxCount(m, n, ops);

    std::cout << "Output: " << result << std::endl; // Output: 4

    return 0;
}
