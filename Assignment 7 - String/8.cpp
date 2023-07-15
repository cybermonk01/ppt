#include <iostream>
#include <vector>

bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
    if (coordinates.size() <= 2) {
        return true;
    }

    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    double expected_slope = static_cast<double>(y2 - y1) / (x2 - x1);

    for (int i = 2; i < coordinates.size(); ++i) {
        x1 = coordinates[i - 1][0];
        y1 = coordinates[i - 1][1];
        x2 = coordinates[i][0];
        y2 = coordinates[i][1];
        double slope = static_cast<double>(y2 - y1) / (x2 - x1);

        if (slope != expected_slope) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    if (checkStraightLine(coordinates)) {
        std::cout << "Output: true" << std::endl;
    } else {
        std::cout << "Output: false" << std::endl;
    }
    return 0;
}
